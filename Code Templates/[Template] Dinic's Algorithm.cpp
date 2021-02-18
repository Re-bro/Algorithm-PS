/* Dinic's Algorithm Template

	Time : O(V^2E)
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;
#define MAX_V 410
int S, T;
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
		adj.assign(n + 1, vector<edge>());
		level.assign(n + 1, -1);
		see.assign(n + 1, 0);
	}
	void addedge(int u, int v, int capa) {
		adj[u].push_back({ v, capa, (int)adj[v].size() });
		adj[v].push_back({ u, 0, (int)adj[u].size() - 1 });
	}
	bool bfs() {//level graph �����
		level.assign(n + 1, -1);
		queue<int> q;
		level[S] = 0;
		q.push(S);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto i : adj[u]) {
				//level�� �������� �ʾҰ�, ������ �� �긱 �� ���� ��
				if (level[i.v] == -1 && i.c > 0) {
					level[i.v] = level[u] + 1;
					q.push(i.v);
				}
			}
		}
		return level[T] != -1;
	}
	int dfs(int u, int flow) {
		//see[u] : u���� ���� ���� �ִ� ���� ����Ʈ�� index ��ȣ
		//�������� ������ٰ� �Ǵ��� ������ �ٽ� �� �ʿ䰡 ����
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
		//���� ��� ã�� ���� : ���� 0
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
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	Dinic dc = Dinic(MAX_V);
	/*
		make graph
		dc.addedge(u, v, c)
	*/
	cout << dc.solve();
}