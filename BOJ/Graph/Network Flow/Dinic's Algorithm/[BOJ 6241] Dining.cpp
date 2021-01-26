/* [BOJ 6241] Dining
	Algorithm : Dinic's Algorithm

	���� 1���� ���� 1���� ��� ������ ���� �ִ� ���� ���ϴ� �����̴�.
	�����̳� ���� �� �� �ϳ��� �����Ѵٸ� �ܼ� �̺и�Ī ������ ������, 
	�� �� �����Ƿ� �𵨸��� �ٸ��� ���־���Ѵ�.
	Ư�� �ҿ� ������ ����� ���� 1���� �̴� ������� ������ �� �ִ�.
	��, Source - ���� - �� - ���� - Sink�� ���� �׷����� �����, �Ҵ� ���������� �Ͽ� 
	�Ҹ� �ߺ��ؼ� �������� �ʰ� �ϸ�, (����, ��, ����) �� ���� ��������� �ȴ�.
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;

int N, F, D;
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
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> F >> D;
	Dinic dc = Dinic(401);
	S = 0;
	T = 401;
	for (int i = 1; i <= F; i++) {
		dc.addedge(0, i, 1);
	}
	for (int i = 1; i <= D; i++) {
		dc.addedge(300 + i, T, 1);
	}
	for (int i = 1; i <= N; i++) {
		dc.addedge(100 + i, 200 + i, 1);
		int f, d; cin >> f >> d;
		for (int j = 1; j <= f; j++) {
			int a; cin >> a;
			dc.addedge(a, 100 + i, 1);
		}
		for (int j = 1; j <= d; j++) {
			int a; cin >> a;
			dc.addedge(200 + i, 300 + a, 1);
		}
	}
	cout << dc.solve();
}