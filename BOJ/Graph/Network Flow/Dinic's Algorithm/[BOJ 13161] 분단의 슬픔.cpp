/* [BOJ 13161] 분단의 슬픔
	Algorithm : Min cut / Dinic Algorithm

	N명을 두 집합으로 나누는 문제이므로 S-T cut 문제이다. 
	A 진영을 source라고 하고, B 진영을 sink라고 한 다음, 
	A 진영을 선호하는 경우 Source로 부터 용량이 무한인 간선을 연결하고, 
	B 진영을 선호하는 경우 Sink로 용량이 무한인 간선을 연결한다. 
	S -> T로 유량을 흘렸을 때, 용량과 유량이 일치하는, 즉 최대한 유량을 흘려보내는 간선들을 잘라주면 
	두 집합으로 분리가 되고, 자르는 간선들의 유량의 합이 최소 슬픔 정도가 된다. 
	S에서 유량을 더 흘려보낼 수 있는 정점들이 A 진영이고, 나머지 정점들은 B 진영이다.
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