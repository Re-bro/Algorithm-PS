/* [BOJ 13161] �д��� ����
	Algorithm : Min cut / Dinic Algorithm

	N���� �� �������� ������ �����̹Ƿ� S-T cut �����̴�. 
	A ������ source��� �ϰ�, B ������ sink��� �� ����, 
	A ������ ��ȣ�ϴ� ��� Source�� ���� �뷮�� ������ ������ �����ϰ�, 
	B ������ ��ȣ�ϴ� ��� Sink�� �뷮�� ������ ������ �����Ѵ�. 
	S -> T�� ������ ����� ��, �뷮�� ������ ��ġ�ϴ�, �� �ִ��� ������ ��������� �������� �߶��ָ� 
	�� �������� �и��� �ǰ�, �ڸ��� �������� ������ ���� �ּ� ���� ������ �ȴ�. 
	S���� ������ �� ������� �� �ִ� �������� A �����̰�, ������ �������� B �����̴�.
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;
#define MAX_V 510

int N;
int c[MAX_V][MAX_V], f[MAX_V][MAX_V], level[MAX_V], see[MAX_V];
int S, T;
vector<int> adj[MAX_V];

bool bfs() {
	fill(level, level + MAX_V, -1);
	level[S] = 0;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
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
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	S = 0;
	T = N + 1;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		if (a == 1) {
			c[S][i] = MAX;
			adj[S].push_back(i);
			adj[i].push_back(S);
		}
		else if (a == 2) {
			c[i][T] = MAX;
			adj[i].push_back(T);
			adj[T].push_back(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> c[i][j];
			if(i != j) adj[i].push_back(j);
		}
	}
	int res = 0;
	while (bfs()) {
		memset(see, 0, sizeof(see));
		while (1) {
			int flow = dfs(S, MAX);
			if (!flow) break;
			res += flow;
		}
	}
	cout << res<<'\n';
	for (int i = 1; i <= N; i++) {
		if (level[i] != -1) cout << i << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= N; i++) {
		if (level[i] == -1) cout << i << ' ';
	}
	cout << '\n';
}