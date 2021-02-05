/* [BOJ 16993] 연속합과 쿼리
	Algorithm : Segment Tree

	구간 [l, r]의 연속합의 최대는 [l, (l+r)/2]에서의 최대, [(l+r)/2+1, r]에서의 최대, 
	[(l+r)/2-a1, (l+r)/2+1 +a2] 에서의 최대 중 하나이다. 
	따라서 트리의 노드로 왼쪽, 오른쪽, 중간, 합 총 네 변수를 두고, 
	분할정복 기법으로 구해나간다. 
	이미 알고 있는 구간에 대해서 반복적으로 계산하지 않도록 세그먼트 트리를 이용해서 저장해둔다.
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