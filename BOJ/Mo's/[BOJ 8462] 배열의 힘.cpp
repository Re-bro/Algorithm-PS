/*
	[BOJ 8462] ¹è¿­ÀÇ Èû
	Algorithm : mo's algorithm / offline query
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
#define fi first
#define se second

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);

ll a[101010];
ll cnt[1010101];
ll ans[101010];
int n, t;
bool cmp(tuple<int, int, int> t1, tuple<int, int, int> t2) {
	auto[l1, r1, x] = t1;
	auto[l2, r2, y] = t2;
	int rt = (int)sqrt(n);
	if (r1 / rt == r2 / rt) return l1 < l2;
	else return r1 / rt < r2 / rt;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<tuple<int, int, int>> q;
	for (int i = 1; i <= t; i++) {
		int l, r; cin >> l >> r;
		q.pb(make_tuple(l, r, i));
	}
	sort(all(q), cmp);
	int L = 1, R = 0;
	ll res = 0;
	for (auto[l, r, i] : q) {
		while (L < l) {
			res -= cnt[a[L]] * cnt[a[L]] * a[L];
			cnt[a[L]]--;
			res += cnt[a[L]] * cnt[a[L]] * a[L];
			L++;
		}
		while (L > l) {
			L--;
			res -= cnt[a[L]] * cnt[a[L]] * a[L];
			cnt[a[L]]++;
			res += cnt[a[L]] * cnt[a[L]] * a[L];
		}
		while (R < r) {
			R++;
			res -= cnt[a[R]] * cnt[a[R]] * a[R];
			cnt[a[R]]++;
			res += cnt[a[R]] * cnt[a[R]] * a[R];
		}
		while (R > r) {
			res -= cnt[a[R]] * cnt[a[R]] * a[R];
			cnt[a[R]]--;
			res += cnt[a[R]] * cnt[a[R]] * a[R];
			R--;
		}
		ans[i] = res;
	}
	for (int i = 1; i <= t; i++) cout << ans[i] << '\n';
}