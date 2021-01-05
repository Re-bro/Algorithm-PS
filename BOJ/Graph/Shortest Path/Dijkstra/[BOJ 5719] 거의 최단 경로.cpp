/* [BOJ 5719] 거의 최단 경로
	Algorithm : Dijkstra algorithm

	먼저, 다익스트라 알고리즘으로 최단경로의 길이를 구해준다. 
	만약 u -> v 간선이 최단경로에 속한다면, dis(s, v)는 dis(s, u) + dis(u, v) 를 만족해야 하며 이는 필요충분이다.
	따라서 끝점부터 역간선을 타고 v -> u 간선의 가중치 = dis(s, v) - dis(s, u)를 만족하면 간선 (u, v)를 제거해준다.
	최종적으로 다시 다익스트라를 돌려서 최단 경로를 구해준다. 
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);

vector<vector<pii>>adj, readj;
int dis[501];
bool can[501][501];
int n, m, s, d;
bool visited[501];
void dijkstra() {
	priority_queue<pii> pq;
	dis[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (cost > dis[now]) continue;
		for (pii p : adj[now]) {
			int next = p.first;
			int edge = p.second;
			if (dis[next] > dis[now] + edge && can[now][next]) {
				dis[next] = dis[now] + edge;
				pq.push({ -dis[next], next });
			}
		}
	}
}
void del(int u) {
	visited[u] = true;
	for (pii v : readj[u]) {
		if (v.second + dis[v.first] == dis[u]) {
			can[v.first][u] = false;
			if(!visited[v.first]) del(v.first);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	while (1) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			dis[i] = MAX;
			visited[i] = false;
			for (int j = 0; j < n; j++) can[i][j] = true;
		}
		adj.assign(n, vector<pii>());
		readj.assign(n, vector<pii>());
		if (n == 0 && m == 0) break;
		cin >> s >> d;
		for (int i = 1; i <= m; i++) {
			int u, v, p; cin >> u >> v >> p;
			adj[u].push_back({ v, p });
			readj[v].push_back({ u, p });
		}
		dijkstra();
		del(d);
		for (int i = 0; i < n; i++) dis[i] = MAX;
		dijkstra();
		if (dis[d] == MAX) cout << -1 << '\n';
		else cout << dis[d] << '\n';
	}
}