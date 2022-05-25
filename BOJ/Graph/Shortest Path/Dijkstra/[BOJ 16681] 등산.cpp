#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll h[101010];
vector<pair<int, int>> adj[101010];
ll dis1[101010], dis2[101010];
void dijkstra(ll dis[], int s) {
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (dis[u] < -d) continue;
		for (auto [v, c] : adj[u]) {
			if (h[v] <= h[u] || dis[v] <= -d + c) continue;
			dis[v] = -d + c;
			pq.push({ -dis[v], v });
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, d, e; cin >> n >> m >> d >> e;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= m; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	fill(dis1, dis1 + n + 1, (ll)1e18);
	fill(dis2, dis2 + n + 1, (ll)1e18);
	dis1[1] = 0;
	dis2[n] = 0;
	dijkstra(dis1, 1);
	dijkstra(dis2, n);
	ll ans = (ll)-1e18;
	for (int i = 2; i < n; i++) {
		if (dis1[i] == (ll)1e18 || dis2[i] == (ll)1e18) continue;
		ans = max(ans, h[i] * e - (dis1[i] + dis2[i]) * d);
	}
	if (ans == (ll)-1e18) cout << "Impossible";
	else cout << ans;
}