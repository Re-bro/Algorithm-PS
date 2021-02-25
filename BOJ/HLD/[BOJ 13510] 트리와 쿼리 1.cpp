/*
	[BOJ 13510] 트리와 쿼리 1
	Algorithm : HLD / Segment Tree
	각 정점에서 부모로 가는 간선은 유일하므로, 간선의 가중치를 자식 정점의 가중치로 생각해도 된다.
	따라서, 간선의 최댓값을 정점의 최댓값으로 고려한다.
*/

#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
int n, num; 
#define MAXV 100001
int sz[MAXV], dep[MAXV], par[MAXV], top[MAXV], in[MAXV], out[MAXV], tr[4*MAXV];
vector<pii> adj[MAXV];
vector<pii> edge;
int update(int x, int s, int e, int i, int val) {
	if (i > e || i < s) return tr[x];
	if (s == e) return tr[x] = val;
	return tr[x] = max(update(x * 2, s, (s + e) / 2, i, val), update(x * 2 + 1, (s + e) / 2 + 1, e, i, val));
}
int mx(int x, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	else if (s >= l && e <= r) return tr[x];
	else return max(mx(x * 2, s, (s + e) / 2, l, r), mx(x * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
void dfs1(int u, int p) {
	sz[u] = 1;
	for (auto &v : adj[u]) {
		if (v.fi == p) continue;
		dep[v.fi] = dep[u] + 1; par[v.fi] = u;
		dfs1(v.fi, u); sz[u] += sz[v.fi];
		if (sz[v.fi] > sz[adj[u][0].fi]) swap(v, adj[u][0]);
	}
}
void dfs2(int u, int p) {
	in[u] = ++num;
	for (auto[v, c] : adj[u]) {
		if (v == p) continue;
		top[v] = (v == adj[u][0].fi ? top[u] : v);
		dfs2(v, u);
		update(1, 1, n, in[v], c);
	}
	out[u] = num;
}
int query(int a, int b) {
	int ret = 0;
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		ret = max(ret, mx(1, 1, n, in[top[a]], in[a]));
		a = par[top[a]];
	}
	if (dep[a] > dep[b]) swap(a, b);
	else if(dep[a] == dep[b]) return ret;
	a = adj[a][0].first;
	ret = max(ret, mx(1, 1, n, in[a], in[b]));
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	edge.assign(n, pii());
	for (int i = 1; i < n; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
		edge[i] = { u, v };
	}
	dfs1(1, 1);
	dfs2(1, 1);
	int m; cin >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			auto[u, v] = edge[b];
			if (in[u] < in[v]) swap(u, v);
			update(1, 1, n, in[u], c);
		}
		else {
			cout << query(b, c)<<'\n';
		}
	}
}