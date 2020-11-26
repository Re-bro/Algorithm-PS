/* [BOJ 18118] 7-세그먼트 디스플레이
	Algorithm : DP

	dp[n][r] = m으로 나눴을 때 나머지가 r인 수 중 가장 큰 수
	dp[n-1][r] 뒤에 0 ~ 9, 11을 붙이면 dp[n][~] 에 대해서 업데이트 가능
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);

ll dp[10][100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		ll n, m; cin >> n >> m;
		ini(dp, -1);
		dp[0][0] = 0;
		for (int i = 0; i <= n - 1; i++) {
			for (int j = 0; j < m; j++) {
				if (dp[i][j] == -1) continue;
				for (ll k = 0; k <= 9; k++) {
					dp[i + 1][(dp[i][j] * 10 + k) % m] = max(dp[i + 1][(dp[i][j] * 10 + k) % m], dp[i][j] * 10 + k);
				}
				dp[i + 1][(dp[i][j] * 100 + 11) % m] = max(dp[i + 1][(dp[i][j] * 100 + 11) % m], dp[i][j] * 100 + 11);
			}
		}
		cout << dp[n][0] << '\n';
	}
}