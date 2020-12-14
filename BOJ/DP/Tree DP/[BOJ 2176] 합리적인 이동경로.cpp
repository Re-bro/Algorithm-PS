/* [BOJ 2176] 합리적인 이동경로
	Algorithm : Dijkstra / Tree DP

	S에서 T로 갈 때, T에 가까워지며 이동한다는 의미는, 
	x를 거쳐간다면 dist(S, T) > dist(x, T)를 의미한다.
	따라서 T에서 각 정점까지의 거리를 다익스트라로 구한 뒤, 
	거리가 더 짧아지는 경우에만 dfs를 타고 이동한다. 
	이동경로의 개수는 dp로 구한다.
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using pii = pair<int, int>;
vector<pii>adj[1001];
int dp[1001];
int dis[1001];
void dijk(int s) {
	dis[s] = 0;
	priority_queue<pii> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int cost = -pq.top().first; 
		int u = pq.top().second;
		pq.pop();
		if (dis[u] < cost) continue;
		for (pii v : adj[u]) {
			if (dis[v.first] > cost + v.second) {
				dis[v.first] = cost + v.second;
				pq.push({ -dis[v.first], v.first });
			}
		}
	}
}
int sol(int u) {
	if (u == 2 ) return dp[u] = 1;
	int &ret = dp[u];
	if (ret != -1) return ret;
	ret = 0;
	for (pii v : adj[u]) {
		if (dis[v.first] < dis[u]) {
			ret += sol(v.first);
		}
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M; cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	ini(dp, -1);
	fill(dis, dis + N + 1, (int)2e9);
	dijk(2);
	cout << sol(1);
}