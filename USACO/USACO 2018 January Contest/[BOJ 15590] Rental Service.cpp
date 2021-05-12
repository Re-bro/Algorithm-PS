/*
	[BOJ 15590] Rental Service
	Algorithm : Greedy / Prefix sum
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll c[101010];
ll r[101010];
ll amount[101010];
ll earn[101010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n, m, R; cin >> n >> m >> R;
	ll sum = 0;
	for (int i = 1; i <= n; i++) cin >> c[i], sum += c[i];
	vector<pll> store;
	for (int i = 1; i <= m; i++) {
		int q, p; cin >> q >> p;
		store.pb({ p, q });
	}
	sort(all(store), greater<pll>());
	store.pb({ 0, 0 });
	for (int i = 0; i < m; i++) {
		amount[i + 1] += amount[i] + store[i].second;
		earn[i + 1] = earn[i] + store[i].first*store[i].second;
	}
	for (int i = 1; i <= R; i++) {
		cin >> r[i];
	}
	sort(r + 1, r + 1 + R, greater<ll>());
	sort(c + 1, c + 1 + n);
	ll ans = 0;
	ll rent = 0;
	ll prv = 0;
	for (int i = 0; i <= min(R, n); i++) {
		rent += c[i];
		int x = lower_bound(amount + 1, amount + 1 + m, sum - rent) - amount;
		x--;
		ans = max(ans, r[i]+ earn[x] + (sum - rent - amount[x])*store[x].first);
		r[i + 1] += r[i];
	}
	cout << ans;
}