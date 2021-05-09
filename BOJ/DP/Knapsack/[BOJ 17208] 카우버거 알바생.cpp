/*
	[BOJ 17208] 카우버거 알바생
	Algorithm : DP / knapsack
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
int dp[301][301];
int tmp[301][301];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	int n, m, k; cin >> n >> m >> k;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		ini(tmp, 0);
		for (int q = m - x; q >= 0; q--) {
			for (int s = k - y; s >= 0; s--) {
				tmp[q][s] = max(dp[q][s], dp[q + x][s + y] + 1);
			}
		}
		for (int q = m - x; q >= 0; q--) {
			for (int s = k - y; s >= 0; s--) {
				dp[q][s] = tmp[q][s];
				ans = max(ans, dp[q][s]);
			}
		}
	}
	cout << ans;
}