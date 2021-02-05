/* [BOJ 16993] �����հ� ����
	Algorithm : Segment Tree

	���� [l, r]�� �������� �ִ�� [l, (l+r)/2]������ �ִ�, [(l+r)/2+1, r]������ �ִ�, 
	[(l+r)/2-a1, (l+r)/2+1 +a2] ������ �ִ� �� �ϳ��̴�. 
	���� Ʈ���� ���� ����, ������, �߰�, �� �� �� ������ �ΰ�, 
	�������� ������� ���س�����. 
	�̹� �˰� �ִ� ������ ���ؼ� �ݺ������� ������� �ʵ��� ���׸�Ʈ Ʈ���� �̿��ؼ� �����صд�.
*/
#include<bits/stdc++.h>

using namespace std;
const int MAX = (int)1e9;
struct node {
	int L, R, mid, sum;
};
node tr[400001];
int A[100001];
int ans = 0;
void init(int x, int s, int e) {
	if (s == e) {
		tr[x].L = tr[x].R = tr[x].mid = tr[x].sum = A[s];
		return;
	}
	init(x * 2, s, (s + e) / 2);
	init(x * 2 + 1, (s + e) / 2 + 1, e);
	tr[x].mid = max({tr[x * 2].R + tr[x * 2 + 1].L, tr[x * 2].mid, tr[x * 2 + 1].mid});
	tr[x].L = max(tr[x * 2].L, tr[x * 2].sum + tr[x * 2 + 1].L);
	tr[x].R = max(tr[x * 2 + 1].R, tr[x * 2].R + tr[x * 2 + 1].sum);
	tr[x].sum = tr[x * 2].sum + tr[x * 2 + 1].sum;
}
node sum(int x, int s, int e, int l, int r) {
	if (s > r || e < l) return { -MAX, -MAX, -MAX, 0};
	if (s >= l && e <= r) {
		return tr[x];
	}
	else {
		node k1 = sum(x * 2, s, (s + e) / 2, l, r);
		node k2 = sum(x * 2 + 1, (s + e) / 2 + 1, e, l, r);
		node tmp;
		tmp.mid = max({ k1.mid, k2.mid, k1.R + k2.L });
		tmp.L = max(k1.L, k1.sum + k2.L);
		tmp.R = max(k2.R, k2.sum + k1.R);
		tmp.sum = k1.sum + k2.sum;
		return tmp;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	init(1, 1, n);
	int M; cin >> M;
	for (int i = 1; i <= M; i++) {
		int l, r; cin >> l >> r;
		node ans = sum(1, 1, n, l, r);
		cout << max({ ans.L, ans.R, ans.mid }) << '\n';
	}
}