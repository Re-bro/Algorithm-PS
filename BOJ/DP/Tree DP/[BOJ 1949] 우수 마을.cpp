/* [BOJ 1949] 우수 마을
	Algorithm : Tree DP

	주어진 그래프가 트리이므로, 각 노드별로 부모 노드와 자식 노드만 고려해주면
	인접한 마을에 대해서 모두 고려가 가능하다. 
	dfs로 순회하면서, 현재 마을을 우수 마을로 선정하기 위해서는 자손들이 모두 우수 마을이 아니어야 한다. 
	반면, 현재 마을이 우수 마을로 선정되지 않는다면
	자손들은 우수 마을의 여부와 상관없이 최대의 값을 갖는 경우를 고려하면 된다. 
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
int dp[10001][2];
bool visited[10001];
void sol(int u, int p) {
	for (int v : adj[u]) {
		if (v == p) continue;
		sol(v, u);
		dp[u][0] += max(dp[v][0], dp[v][1]);
		dp[u][1] += dp[v][0];
	}
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> dp[i][1];
	for (int i = 1; i < N; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	sol(1, 1);
	cout << max(dp[1][0], dp[1][1]);
}