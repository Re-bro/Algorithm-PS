/* Dinic's Algorithm Template

	Time : O(V^2E)
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX_V 501

int c[MAX_V][MAX_V], f[MAX_V][MAX_V], level[MAX_V], see[MAX_V];
int S, T;
vector<int> adj[MAX_V];

bool bfs() { //level graph �����
	fill(level, level + MAX_V, -1);
	level[S] = 0;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			//level�� �������� �ʾҰ�, ������ �� �긱 �� ���� ��
			if (level[v] == -1 && c[u][v] - f[u][v] > 0) {
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
	return level[T] != -1;
}
int dfs(int u, int flow) {
	if (u == T) return flow;
	//see[u] : u���� ���� ���� �ִ� ���� ����Ʈ�� index ��ȣ
	//�������� ������ٰ� �Ǵ��� ������ �ٽ� �� �ʿ䰡 ����
	for (; see[u] < adj[u].size(); see[u]++) {
		int v = adj[u][see[u]];
		if (level[v] == level[u] + 1 && c[u][v] > f[u][v]) {
			int now = dfs(v, min(flow, c[u][v] - f[u][v]));
			if (now > 0) {
				f[u][v] += now;
				f[v][u] -= now;
				return now;
			}
		}
	}
	//���� ��� ã�� ���� : ���� 0
	return 0;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	/*
		Making adjacent graph CODE
	*/
	int res = 0;
	while (bfs()) {
		memset(see, 0, sizeof(see));
		while (1) {
			int flow = dfs(S, 2e9);
			if (!flow) break;
			res += flow;
		}
	}
	cout << res;
}