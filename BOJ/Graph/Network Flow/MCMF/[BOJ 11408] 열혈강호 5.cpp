/* [BOJ 11408] 열혈강호 5
	Algorithm : MCMF

*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
using namespace std;
const int MAX = (int)2e9;
#define MAX_V 810

int N, M;
//0 : source, 1 ~ N : person , N+1 ~ N+M : work , N+M+1 : sink
int c[MAX_V][MAX_V]; //각 간선의 용량
int d[MAX_V][MAX_V]; //각 간선의 비용
int f[MAX_V][MAX_V]; //각 간선에 흐르는 유량
vector<int> adj[810];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		adj[0].push_back(i);
		adj[i].push_back(0);
		c[0][i] = 1;
		int k; cin >> k;
		while (k--) {
			int a, b; cin >> a >> b;
			adj[i].push_back(N + a);
			adj[N + a].push_back(i);
			d[i][N + a] = b;
			d[N + a][i] = -b;
			c[i][N + a] = 1;
		}
	}
	for (int i = N + 1; i <= N + M; i++) {
		c[i][N + M + 1] = 1;
		adj[i].push_back(N + M + 1);
		adj[N + M + 1].push_back(i);
	}
	int maxflow = 0;
	int mincost = 0;
	while (1) {
		vector<int> P(MAX_V, -1), dis(MAX_V, MAX), inQ(MAX_V);
		//SPFA
		queue<int> q;
		dis[0] = 0;
		inQ[0] = 1;
		q.push(0);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			inQ[u] = false;
			for (int v : adj[u]) {
				if (c[u][v] - f[u][v] > 0 && dis[v] > dis[u] + d[u][v]) {
					dis[v] = dis[u] + d[u][v];
					P[v] = u;
					if (!inQ[v]) {
						q.push(v);
						inQ[v] = 1;
					}
				}
			}
		}
		if (P[N + M + 1] == -1) break;
		int flow = MAX;
		for (int i = N + M + 1; i != 0; i = P[i]) {
			flow = min(flow, c[P[i]][i] - f[P[i]][i]);
		}
		for (int i = N + M + 1; i != 0; i = P[i]) {
			mincost += flow * d[P[i]][i];
			f[P[i]][i] += flow;
			f[i][P[i]] -= flow;
		}
		maxflow += flow;
	}
	cout << maxflow << '\n' << mincost;
}