/* [BOJ 13141] ignition
	Algorithm : Dijkstra or Bellman-Ford
	
	어떤 두 정점 u, v를 잇는 간선의 길이를 w라고 한다면, 
	시작점에서 u와 v까지의 최단 거리를 dis[u] , dis[v]라고 할 때, 
	간선을 모두 태우는데 걸리는 시간은
	abs(dis[u] - dis[v]) >= w 일 때, min(dis[u], dis[v]) + w
	abs(dis[u]-dis[v]) <w 이면, (w - abs(dis[u] - dis[v]))/2 + max(dis[u] , dis[v]) 이다.

	간선들만 따로 모아서 계산하면 O(NM + N^3)만에 가능하다. (벨만포드) 
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);

int N, M;
vector<vector<pii>>adj;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	adj.assign(N + 1, vector<pii>());
	vector<vector<int>> dist(N + 1, vector<int>(N + 1, 1e9));
	for (int i = 1; i <= N; i++) dist[i][i] = 0;
	for (int i = 1; i <= M; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].push_back({ v, c });
		adj[v].push_back({ u,c });
		dist[u][v] = min(dist[u][v], c);
		dist[v][u] = min(dist[v][u], c);
	}
	double ans = MAX;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		double tmp = 0;
		for (int j = 1; j <= N; j++) {
			for (pii v : adj[j]) {
				if (v.first < j) continue;
				int len = v.second;
				if (dist[i][j] >= dist[i][v.first] + len) {
					tmp = max(tmp, (double)dist[i][v.first] + len);
				}
				else if (dist[i][j] + len <= dist[i][v.first]) {
					tmp = max(tmp, (double)dist[i][j] + len);
				}
				else {
					len -= abs(dist[i][v.first] - dist[i][j]);
					if (dist[i][v.first] >= dist[i][j]) tmp = max(tmp, dist[i][v.first] + len / 2.0);
					else tmp = max(tmp, dist[i][j] + len / 2.0);
				}
			}
		}
		ans = min(ans, tmp);
	}
	cout << fixed;
	cout.precision(1);
	cout << ans;
}