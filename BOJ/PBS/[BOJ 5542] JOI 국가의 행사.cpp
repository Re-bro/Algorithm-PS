/*
	[BOJ 5542] JOI 국가의 행사
	Algorithm : PBS / Disjoint-set / Dijkstra
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
const int MAX = (int)2e9;

vector<pii> adj[101010];
int dis[101010];
pii query[101010];
int P[101010], L[101010], R[101010], ans[101010];
vector<int> g[202020];
int find(int a) {
	return P[a] < 0 ? a : P[a] = find(P[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (P[a] > P[b]) swap(a, b);
		P[a] += P[b];
		P[b] = a;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, k, q; cin >> n >> m >> k >> q;
	vector<pair<int, pii>> edge;
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].pb({ v, c });
		adj[v].pb({ u, c });
		edge.pb({ 0, { u, v } });
	}
	for (int i = 1; i <= n; i++) dis[i] = MAX, L[i] = 1, R[i] = m;
	priority_queue<pii> pq;
	for (int i = 1; i <= k; i++) {
		int a; cin >> a;
		pq.push({ 0, a });
		dis[a] = 0;
	}
	while (!pq.empty()) {
		auto[d, u] = pq.top(); pq.pop();
		if (dis[u] < -d) continue;
		for (auto[v, c] : adj[u]) {
			if (dis[v] > -d + c) {
				dis[v] = -d + c;
				pq.push({ -dis[v], v });
			}
		}
	}
	for (int i = 0; i < m; i++) {
		edge[i].first = min(dis[edge[i].second.first], dis[edge[i].second.second]);
	}
	sort(all(edge), greater<pair<int, pii>>());
	for (int i = 1; i <= q; i++) {
		cin >> query[i].fi >> query[i].se;
	}
	while (1) {
		int s = 0;
		bool chk = false;
		int mi = MAX;
		for (int i = 1; i <= m; i++) g[i].clear();
		for (int i = 1; i <= q; i++) {
			if (L[i] <= R[i]) {
				g[(L[i] + R[i]) / 2].pb(i);
				chk = true;
			}
		}
		if (!chk) break;
		ini(P, -1);
		for (int i = 1; i <= m; i++) {
			auto[u, v] = edge[i-1].second;
			merge(u, v);
			mi = min({ edge[i-1].first, mi });
			for (int j : g[i]) {
				if (find(query[j].first) == find(query[j].second)) {
					R[j] = i - 1;
					ans[j] = mi;
				}
				else {
					L[j] = i + 1;
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << '\n';
	}
}