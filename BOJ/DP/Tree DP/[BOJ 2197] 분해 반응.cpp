/* [BOJ 2197] 분해 반응
	Algorithm : Tree DP

	2332 트리자르기 문제와 동일
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);

int n, m; 
vector<int> adj[151];
int dp[151][151];
int tmp[160], sub[160];
void sol(int u, int p) {
	sub[u] = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		sol(v, u);
		sub[u] += sub[v];
		fill(tmp, tmp + n + 1, 1000);
		for (int i = 1; i <= sub[u]; i++) {
			for (int j = 0; j <= sub[v]; j++) {
				tmp[i + j] = min(tmp[i + j], dp[u][i] + (j == 0 ? 1 : dp[v][j]));
			}
		}
		for (int i = 1; i <= n; i++) dp[u][i] = tmp[i];
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		dp[i][1] = 0;
		for (int j = 2; j <= n; j++) dp[i][j] = 1000;
	}
	sol(1, 1);
	int ans = MAX;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, dp[i][m] + (i == 1 ? 0 : 1));
	}
	cout << ans;
}