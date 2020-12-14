/* [BOJ 1693] 트리 색칠하기
	Algorithm : Tree DP

	S(N) = 반드시 N개의 색을 써야 최소 cost로 색칠할 수 있는 그래프의 노드 수 중 최소라 하면
	S(N) >= 2^(N-1)이다. 
	따라서, log(노드의 개수) 만큼만 색이 있으면 되므로 dp[N][logN] 만큼 선언하여
	Tree dp를 이용해주면 된다.
	https://blog.encrypted.gg/144
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;
vector<int> adj[100001];
int n;
int dp[100001][18];
void sol(int u, int p) {
	for (int v : adj[u]) {
		if (v == p) continue;
		sol(v, u);
		for (int i = 1; i < 18; i++) {
			int mi = MAX;
			for (int j = 1; j < 18; j++) {
				if(j != i) mi = min(mi, dp[v][j]);
			}
			dp[u][i] += mi;
		}
	}
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 18; j++) dp[i][j] = j;
	}
	sol(1, 1);
	int ans = MAX;
	for (int i = 1; i < 18; i++) ans = min(ans, dp[1][i]);
	cout << ans;
}