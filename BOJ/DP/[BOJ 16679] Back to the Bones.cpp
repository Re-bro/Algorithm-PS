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
const int MAX = (int)1e9;
const double PI = acos(-1);

ll dp[22][150];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		vector<pii> v;
		int sum = 0;
		ll p6 = 1;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			v.pb({ a, i });
			sum += a;
			p6 *= 6;
		}
		if (sum >= k) {
			cout << p6 << '\n';
			for (int i = 1; i <= n; i++) cout << 0 << ' ';
			cout << '\n';
			continue;
		}
		sort(all(v));
		ini(dp, 0);
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 6 * n; j++) {
				for (int q = 1; q <= 6; q++) {
					if (j - q >= 0 && dp[i - 1][j - q] != 0) {
						dp[i][j] += dp[i - 1][j - q];
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 6 * n; j >= 0; j--) {
				dp[i][j] += dp[i][j + 1];
			}
		}
		ll ans = dp[0][max(0, k - sum)];
		int idx = -1;
		for (int i = 0; i < n; i++) {
			sum -= v[i].first;
			p6 /= 6;
			if (ans < dp[i + 1][max(0, k - sum)] * p6) {
				ans = dp[i + 1][max(0, k - sum)] * p6;
				idx = i;
			}
		}
		vector<int> chk(n + 1);
		for (int i = 0; i <= idx; i++) {
			chk[v[i].second] = 1;
		}
		cout << ans << '\n';
		for (int i = 1; i <= n; i++) cout << chk[i] << ' ';
		cout << '\n';
	}
}