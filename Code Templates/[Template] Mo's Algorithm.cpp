/* 
	O((N + Q) * sqrt(N))
	[BOJ 14897] 서로 다른 수와 쿼리 1 solution
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
using namespace std;

int a[1010101], ans[1010101], n, cnt[1010101], Q, res;
struct query {
	int l, r, i;
	bool operator < (query q) {
		int rt = 2000;
		int l1 = l, l2 = q.l;
		if ((r / rt) & 1) l1 = -l1;
		if ((q.r / rt) & 1) l2 = -l2;
		if (r / rt == q.r / rt) return l1 < l2;
		return r / rt < q.r / rt;
	}
};
void sub(int x) {
	if (--cnt[a[x]] == 0) res--;
}
void add(int x) {
	if (++cnt[a[x]] == 1) res++;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; i++) cin >> a[i], v.pb(a[i]);
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
	}
	cin >> Q;
	vector<query> q;
	for (int i = 1; i <= Q; i++) {
		int l, r; cin >> l >> r;
		q.push_back({ l, r, i });
	}
	sort(all(q));
	int L = 1, R = 0;
	for (auto [l, r, i] : q) {
		while (L < l) sub(L++);
		while (L > l) add(--L);
		while (R < r) add(++R);
		while (R > r) sub(R--);
		ans[i] = res;
	}
	for (int i = 1; i <= Q; i++) cout << ans[i] << '\n';
}