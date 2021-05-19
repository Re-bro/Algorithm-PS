/*
	[BOJ 21590] Investigating Imposter
	Algorithm : Graph
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
using namespace std;

using namespace std;
vector<int> adj[501];
bool visited[501];
void dfs(int u) {
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) dfs(v);
	}
}
int main(void) {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int s; cin >> s;
		while (s--) {
			int v; cin >> v;
			adj[v].pb(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		ini(visited, 0);
		dfs(i);
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (visited[j]) cnt++;
		}
		if (cnt > k) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}