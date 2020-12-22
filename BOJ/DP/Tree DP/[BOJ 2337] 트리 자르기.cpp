/* [BOJ 2337] 트리 자르기
	Algorithm : Tree DP

	dp[u][k] = u를 루트로 하는 서브트리에서 k개 노드가 남도록 자르는 최소 횟수라고 하면
	dp[u][i+j] = min(dp[u][i+j], dp[u][i] + dp[v][j]) 이다. (v는 자손)
	이 때, 기본적으로 dp[u][1]은 처음에 0이므로 전처리 해주고, 
	j가 0인 경우는 자손을 붙이지 않는 경우, 즉 자르는 경우이기 때문에 + dp[v][j] 대신 +1 을 해준다.

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[151];
int sub[151], tmp[151], dp[151][151];
int n, m;
void sol(int u, int p) {
	sub[u] = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		sol(v, u);
		sub[u] += sub[v];
		fill(tmp, tmp + n + 1, 10000);
		for (int i = 1; i <= sub[u]; i++) {
			for (int j = 0; j <= sub[v]; j++) {
				tmp[i+j] = min(tmp[i+j], dp[u][i] + (j == 0 ? 1 : dp[v][j]));
			}
		}
		for (int i = 1; i <= n; i++) dp[u][i] = tmp[i];
	}
	return;
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
		for (int j = 2; j <= n; j++) dp[i][j] = 10000;
	}
	sol(1, 1);
	int ans = 10000;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, dp[i][m] + (i == 1 ? 0 : 1));
	}
	cout << ans;
}