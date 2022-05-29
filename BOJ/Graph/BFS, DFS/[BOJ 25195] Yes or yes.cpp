#include<bits/stdc++.h>

using namespace std;

vector<int> adj[101010];
bool gom[101010], visited[101010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	int s; cin >> s;
	while (s--) {
		int k; cin >> k;
		gom[k] = true;
	}
	queue<int> q;
	if (!gom[1]) {
		q.push(1);
		visited[1] = true;
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (!gom[v] && !visited[v]) {
				q.push(v);
				visited[v] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] && !gom[i] && adj[i].size() == 0) {
			return cout << "yes", 0;
		}
	}
	cout << "Yes";
}