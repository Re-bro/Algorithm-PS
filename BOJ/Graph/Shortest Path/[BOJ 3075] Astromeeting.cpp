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

int a[101];
int dis[101][101];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, p, q; cin >> n >> p >> q;
		for (int i = 1; i <= p; i++) {
			for (int j = 1; j <= p; j++) {
				if (i == j) dis[i][j] = 0;
				else dis[i][j] = 1e6;
			}
		}
		for (int i = 1; i <= n; i++) cin >> a[i];
		while (q--) {
			int u, v, d; cin >> u >> v >> d;
			dis[u][v] = min(dis[u][v], d);
			dis[v][u] = min(dis[v][u], d);
		}
		for (int k = 1; k <= p; k++) {
			for (int i = 1; i <= p; i++) {
				for (int j = 1; j <= p; j++) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
		int ans;
		ll res = 1e18;
		for (int i = 1; i <= p; i++) {
			ll sum = 0;
			for (int j = 1; j <= n; j++) {
				sum += (ll)dis[i][a[j]] * dis[i][a[j]];
			}
			if (sum < res) {
				res = sum;
				ans = i;
			}
		}
		cout << ans << ' ' << res << '\n';
	}
}