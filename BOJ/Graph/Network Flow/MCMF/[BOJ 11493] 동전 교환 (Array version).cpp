/* [BOJ 11493] 동전 교환 (Array version)
	Algorithm : MCMF
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
const int MAX = (int)2e9;

#define MAX_V 510
int N, M;
int S, T;
int c[MAX_V][MAX_V]; //각 간선의 용량
int d[MAX_V][MAX_V]; //각 간선의 비용
int f[MAX_V][MAX_V]; //각 간선에 흐르는 유량
vector<int> adj[MAX_V];
int ver[MAX_V], coin[MAX_V];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int tc; cin >> tc;
	while (tc--) {
		int n, m; cin >> n >> m;
		ini(c, 0); ini(d, 0); ini(f, 0);  ini(ver, 0); ini(coin, 0);
		for (int i = 0; i < 510; i++) adj[i].clear();
		S = 0;
		T = 501;
		while (m--) {
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			c[x][y] = c[y][x] = 100000;
			d[x][y] = d[y][x] = 1;
		}
		for (int i = 1; i <= n; i++) cin >> ver[i];
		for (int i = 1; i <= n; i++) cin >> coin[i];
		for (int i = 1; i <= n; i++) {
			if (ver[i] != coin[i]) {
				if (ver[i] == 0) {
					adj[S].push_back(i);
					c[S][i] = 1;
				}
				else {
					adj[i].push_back(T);
					c[i][T] = 1;
				}
			}
		}
		int mincost = 0;
		while (1) {
			vector<int> P(MAX_V, -1), dis(MAX_V, MAX), inQ(MAX_V);
			queue<int> q;
			dis[S] = 0;
			inQ[S] = 1;
			q.push(S);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				inQ[u] = false;
				for (int v : adj[u]) {
					int dir = (f[u][v] >= 0 ? 1 : -1);
					if (c[u][v] - f[u][v] > 0 && dis[v] > dis[u] + dir*d[u][v]) {
						dis[v] = dis[u] + dir*d[u][v];
						P[v] = u;
						if (!inQ[v]) {
							q.push(v);
							inQ[v] = 1;
						}
					}
				}
			}
			if (P[T] == -1) break;
			for (int i = T; i != S; i = P[i]) {
				int dir = (f[P[i]][i] >= 0 ? 1 : -1);
				mincost +=  dir* d[P[i]][i];
				f[P[i]][i] ++;
				f[i][P[i]] --;
			}
		}
		cout << mincost << '\n';
	}
}