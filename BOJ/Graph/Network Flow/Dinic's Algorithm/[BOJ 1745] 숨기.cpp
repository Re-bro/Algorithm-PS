/* [BOJ 1745] 숨기
	Algorithm : Dinic Algorithm / Binary Search / Floyd-warshall

	특정 방에서 다른 방으로 이동하는 최단 거리를 플로이드-와샬로 구해둔다. 
	그 다음, 이분탐색으로 이동 가능한 통로를 고정한 뒤, 최대 유량이 흐를 수 있으면
	해당 시간은 답의 가능성이 있다. 
	간선이 많으므로 디닉 알고리즘을 이용해야 한다.
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = (int)2e9;

#define MAX_V 410
int S, T;
int F, P;
ll dis[MAX_V][MAX_V];
struct Dinic {
	struct edge {
		int v, c, rev;
		edge(int v, int c, int rev) : v(v), c(c), rev(rev) {}
	};
	int n;
	vector<vector<int>> c, f;
	vector<vector<edge>> adj;
	vector<int> level, see;
	Dinic(int n) : n(n) {
		c.assign(n + 1, vector<int>(n + 1));
		f.assign(n + 1, vector<int>(n + 1));
		adj.assign(n + 1, vector<edge>());
		level.assign(n + 1, -1);
		see.assign(n + 1, 0);
	}
	void addedge(int u, int v, int capa) {
		adj[u].push_back({ v, capa, (int)adj[v].size() });
		adj[v].push_back({ u, 0, (int)adj[u].size() - 1 });
	}
	bool bfs() {
		level.assign(n + 1, -1);
		queue<int> q;
		level[S] = 0;
		q.push(S);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto i : adj[u]) {
				if (level[i.v] == -1 && i.c > 0) {
					level[i.v] = level[u] + 1;
					q.push(i.v);
				}
			}
		}
		return level[T] != -1;
	}
	int dfs(int u, int flow) {
		if (u == T) return flow;
		for (; see[u] < (int)adj[u].size(); see[u]++) {
			auto i = adj[u][see[u]];
			if (level[i.v] == level[u] + 1 && i.c > 0) {
				int now = dfs(i.v, min(flow, i.c));
				if (now > 0) {
					adj[u][see[u]].c -= now;
					adj[i.v][adj[u][see[u]].rev].c += now;
					return now;
				}
			}
		}
		return 0;
	}
	int solve() {
		int ret = 0;
		while (bfs()) {
			see.assign(n + 1, 0);
			while (1) {
				int flow = dfs(S, MAX);
				if (!flow) break;
				ret += flow;
			}
		}
		return ret;
	}
};
int l[201], r[201];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> F >> P;
	S = 0;
	T = 2 * F + 1;
	int total = 0;
	Dinic dc = Dinic(2 * F + 1);
	for (int i = 1; i <= F; i++) {
		cin >> l[i] >> r[i];
		total += l[i];
		for (int j = 1; j <= F; j++) {
			dis[i][j] = (ll)1e13;
		}
		dis[i][i] = 0;
	}
	for (int i = 1; i <= P; i++) {
		int u, v, c;  cin >> u >> v >> c;
		dis[u][v] = min(dis[u][v], (ll)c);
		dis[v][u] = min(dis[v][u], (ll)c);
	}
	for (int i = 1; i <= F; i++) {
		for (int j = 1; j <= F; j++) {
			for (int k = 1; k <= F; k++) {
				dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
			}
		}
	}
	ll s = 0;
	ll e = (ll)1e13;
	ll ans = (ll)1e13;
	while (s <= e) {
		ll mid = (s + e) / 2;
		Dinic dc = Dinic(2 * F + 1);
		for (int i = 1; i <= F; i++) {
			dc.addedge(0, i, l[i]);
			dc.addedge(i + F, T, r[i]);
			dc.addedge(i, i + F, MAX);
			for (int j = 1; j <= F; j++) {
				if (i != j && dis[i][j] <= mid) dc.addedge(i, j + F, MAX);
			}
		}
		if (dc.solve() == total) {
			ans = min(mid, ans);
			e = mid - 1;
		}
		else s = mid + 1;
	}
	if (ans != (ll)1e13) cout << ans;
	else cout << -1;
}