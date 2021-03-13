/*
	[BOJ 18223] 민준이와 마산 그리고 건우
	Algorithm : Dijkstra
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);

vector<pii>adj[5010];
int dijkstra(int S, int T) {
	vector<int> dis(5010, MAX);
	dis[S] = 0;
	priority_queue<pii> pq;
	pq.push({ 0, S });
	while (!pq.empty()) {
		auto [c, u] = pq.top(); pq.pop();
		c = -c;
		if (dis[u] > c) continue;
		for (auto [v, cost] : adj[u]) {
			if (dis[v] > c + cost) {
				dis[v] = c + cost;
				pq.push({ -dis[v], v });
			}
		}
	}
	return dis[T];
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int v, e, p; cin >> v >> e >> p;
	for (int i = 1; i <= e; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].pb({ b, c });
		adj[b].pb({ a, c });
	}
	if (dijkstra(1, v) == dijkstra(1, p) + dijkstra(p, v)) cout << "SAVE HIM";
	else cout << "GOOD BYE";
}