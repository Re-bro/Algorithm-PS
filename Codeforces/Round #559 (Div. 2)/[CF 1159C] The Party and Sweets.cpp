/*
	[CF 1159C] The Party and Sweets
	Algorithm : Math / Greedy
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = (int)2e9;

ll b[100001], g[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	ll mx = 0;
	ll mi = MAX;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		mx = max(mx, b[i]);
	}
	for (int i = 1; i <= m; i++) {
		cin >> g[i];
		mi = min(mi, g[i]);
	}
	if (mx > mi) return cout << -1, 0;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += 1LL * m * b[i];
	}
	if (mi == mx) {
		for (int i = 1; i <= m; i++) {
			ans += g[i] - mx;
		}
	}
	else {
		sort(b + 1, b + 1 + n);
		sort(g + 1, g + 1 + m);
		for (int i = 2; i <= m; i++) {
			ans += g[i] - b[n];
		}
		ans += g[1] - b[n - 1];
	}
	cout << ans;
}