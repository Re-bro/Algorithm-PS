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
const int MOD = (int)998244353;
const int MAX = (int)1e9;
const double PI = acos(-1);

ll dp[2][2][2];
ll mpow(ll a, ll x) {
	ll res = 1;
	while (x > 0) {
		if (x % 2) res = (res * a) % MOD;
		a = (a * a) % MOD;
		x /= 2;
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll h, w, k; cin >> h >> w >> k;
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	dp[0][1][1] = 1;
	for (int i = 1; i <= k; i++) {
		dp[i%2][0][0] = (dp[(i + 1) % 2][1][0] * (h - 1) + dp[(i + 1) % 2][0][1] * (w - 1) + dp[(i + 1) % 2][0][0] * (h - 2 + w - 2)) % MOD;
		dp[i%2][1][0] = (dp[(i + 1) % 2][1][0] * (w - 2) + dp[(i + 1) % 2][0][0] + dp[(i + 1) % 2][1][1] * (w - 1)) % MOD;
		dp[i%2][0][1] = (dp[(i + 1) % 2][0][0] + dp[(i + 1) % 2][0][1] * (h - 2) + dp[(i + 1) % 2][1][1] * (h - 1)) % MOD;
		dp[i%2][1][1] = (dp[(i + 1) % 2][1][0] + dp[(i + 1) % 2][0][1]) % MOD;
	}
	int k1 = (x1 == x2 ? 1 : 0);
	int k2 = (y1 == y2 ? 1 : 0);
	ll ans = dp[k%2][k1][k2];
	if (x1 != x2) {
		ans = ans * mpow(h - 1, MOD - 2) % MOD;
	}
	if (y1 != y2) {
		ans = ans * mpow(w - 1, MOD - 2) % MOD;
	}
	cout << ans;
}