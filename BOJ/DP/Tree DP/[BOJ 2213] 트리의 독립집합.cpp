/* [BOJ 2213] 트리의 독립집합
	Algorithm : Tree dp

	dp[i][j] 
	j = 0 : i번째 노드를 선택안했을 때, j = 1 : i번째 노드를 선택했을 때
	i번째 노드를 선택한다면 자식노드들을 선택할 수 없다.
	반대로 선택하지 않는다면 자식노드를 선택할 수도 있고 안할 수도 있다. 

	경로를 찾을 땐, 자식의 두 dp값 중 더 큰 값을 따라가도록 한다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

int dp[10001][2];
vector<int>adj[10001];
vector<int>ans;
void dfs(int u, int p) {
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		dp[u][0] += max(dp[v][0], dp[v][1]);
		dp[u][1] += dp[v][0];
	}
}
void dfs2(int u, int p, bool chk) {
	if (chk) 	ans.push_back(u);
	for (int v : adj[u]) {
		if (v == p) continue;
		if (chk) 	dfs2(v, u, false);
		else {
			if (dp[v][0] > dp[v][1]) dfs2(v, u, false);
			else dfs2(v, u, true);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dp[i][1];
	}
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	cout << max(dp[1][0], dp[1][1]) << '\n';

	if (dp[1][0] > dp[1][1]) dfs2(1, 1, false);
	else dfs2(1, 1, true);
	sort(all(ans));
	for (int i : ans) cout << i << ' ';
}