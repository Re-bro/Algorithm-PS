/* [BOJ 9867] Optimal Milking
	Algorithm : Segment Tree / Divide and Conquer

	l = ���� ���� �������� �ʴ� ���
	r = ������ ���� �������� �ʴ� ���
	m = ����, ������ ���� �����ص� �Ǵ� ���
	both = ����, ������ ���� �������� �ʴ� ���
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, d; 
struct node {
	ll l, r, m, both;
};
node tr[160001];
void update(int x, int s, int e, int i, ll val) {
	if (i > e || i < s) return;
	if (s == e) {
		tr[x].m = val;
		return;
	}
	update(x * 2, s, (s + e) / 2, i, val);
	update(x * 2 + 1, (s + e) / 2 + 1, e, i, val);
	tr[x].l = max(tr[x * 2].l + tr[x * 2 + 1].l, tr[x * 2 + 1].m + tr[x * 2].both);
	tr[x].r = max(tr[x * 2].r + tr[x * 2 + 1].r, tr[x * 2].m + tr[x * 2 + 1].both);
	tr[x].m = max({ tr[x * 2].r + tr[x * 2 + 1].m, tr[x * 2].m + tr[x * 2 + 1].l, tr[x * 2].r + tr[x * 2 + 1].l});
	tr[x].both = max({ tr[x * 2].both + tr[x * 2 + 1].both, tr[x * 2].l + tr[x * 2 + 1].both, tr[x * 2].both+ tr[x * 2 + 1].r });
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		ll a; cin >> a;
		update(1, 1, n, i, a);
	}
	ll ans = 0;
	for (int i = 1; i <= d; i++) {
		int a, b; cin >> a >> b;
		update(1, 1, n, a, b);
		ans += tr[1].m;
	}
	cout << ans;
}