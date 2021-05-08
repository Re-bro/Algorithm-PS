/*
	[BOJ 16763] Fine Dining
	Algorithm : Dijkstra
*/
	
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MAX = (int)2e9;

int n, m, k;
vector<pii> adj[50505];
int yum[50505];
int dis[50505][2];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int a, b, t; cin >> a >> b >> t;
		adj[a].push_back({ b, t });
		adj[b].push_back({ a, t });
	}
	for (int i = 1; i <= k; i++) {
		int a, b; cin >> a >> b;
		yum[a] = max(yum[a], b);
	}
	for (int i = 1; i <= n; i++) dis[i][0] = dis[i][1] = MAX;
	dis[n][0] = 0;
	priority_queue<tuple<int, int, int>> pq;
	pq.push(make_tuple(0, n, 0));
	while (!pq.empty()) {
		auto[cost, u, a] = pq.top(); pq.pop();
		if (dis[u][a] > -cost) continue;
		for (auto[v, c] : adj[u]) {
			if (a == 0) {
				if (yum[v] > 0) {
					if (-cost + c - yum[v] < dis[v][1]) {
						dis[v][1] = -cost + c - yum[v];
						pq.push(make_tuple(-dis[v][1], v, 1));
					}
				}
				if (-cost + c < dis[v][0]) {
					dis[v][0] = -cost + c;
					pq.push(make_tuple(-dis[v][0], v, 0));
				}
			}
			else {
				if (-cost + c < dis[v][1]) {
					dis[v][1] = -cost + c;
					pq.push(make_tuple( -dis[v][1], v, 1 ));
				}
			}
		}
	}
	for (int i = 1; i < n; i++) {
		if (dis[i][0] >= dis[i][1]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}