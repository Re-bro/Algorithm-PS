/* [BOJ 3736] System Engineer
	Algorithm : Bipartite matching / Hopcroft-karp

	전형적인 이분매칭문제.
	n이 10000으로 커서 호프크로프트 카프 알고리즘이 필요하다.
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;

struct hopcroft_karp {
	int n;
	vector<int> A, B, dist, match, see;
	vector<vector<int>>adj;
	hopcroft_karp(int n) : n(n) {
		A.assign(n + 1, -1);
		B.assign(n + 1, -1);
		dist.assign(n + 1, 0);
		match.assign(n + 1, 0);
		adj.resize(n + 1);
	}
	void addedge(int u, int v) {
		adj[u].push_back(v);
	}
	void bfs() {
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (!match[i]) {
				dist[i] = 0;
				q.push(i);
			}
			else dist[i] = MAX;
		}
		while (!q.empty()) {
			int a = q.front(); q.pop();
			for (int b : adj[a]) {
				if (B[b] != -1 && dist[B[b]] == MAX) {
					dist[B[b]] = dist[a] + 1;
					q.push(B[b]);
				}
			}
		}
	}
	bool dfs(int u) {
		for (; see[u] < (int)adj[u].size(); see[u]++) {
			int v = adj[u][see[u]];
			if (B[v] == -1 || (dist[B[v]] == dist[u] + 1 && dfs(B[v]))) {
				match[u] = true;
				A[u] = v;
				B[v] = u;
				return true;
			}
		}
		return false;
	}
	int solve() {
		int ret = 0;
		while (1) {
			see.assign(n + 1, 0);
			bfs();
			int flow = 0;
			for (int i = 1; i <= n; i++) {
				if (!match[i] && dfs(i)) flow++;
			}
			if (!flow) break;
			ret += flow;
		}
		return ret;
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	while (1) {
		int n; cin >> n;
		if (cin.eof()) break;
		hopcroft_karp hk(n);
		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			cin >> s;
			int q = stoi(s.substr(1, (int)s.size() - 2));
			while (q--) {
				int a; cin >> a;
				hk.addedge(i, a - n + 1);
			}
		}
		cout << hk.solve() << '\n';
	}
}