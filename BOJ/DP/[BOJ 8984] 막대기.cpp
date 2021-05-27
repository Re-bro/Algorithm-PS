/*
	[BOJ 8984] ¸·´ë±â
	Algorithm : DP / Coordinate compression / Sorting
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
ll dp[101010][2];
int n, l;
vector<pii> v;
vector<int> T, D;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		int t, d; cin >> t >> d;
		v.pb({ t, d });
		T.pb(t);
		D.pb(d);
	}
	sort(all(T)); sort(all(D));
	T.erase(unique(all(T)), T.end());
	D.erase(unique(all(D)), D.end());
	sort(all(v));
	for (auto [t, d] : v) {
		ll len = abs(t - d) + l;
		t = lower_bound(all(T), t) - T.begin() + 1;
		d = lower_bound(all(D), d) - D.begin() + 1;
		ll tmp = dp[d][1];
		dp[d][1] = max(dp[d][1], dp[t][0] +len);
		dp[t][0] = max(dp[t][0], tmp + len);
	}
	ll ans = 0;
	for (int i = 0; i <= 100000; i++) {
		ans = max({ ans, dp[i][0], dp[i][1] });
	}
	cout << ans;
}