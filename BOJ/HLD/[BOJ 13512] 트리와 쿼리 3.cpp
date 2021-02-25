/*
	[BOJ 13512] Æ®¸®¿Í Äõ¸® 3
	Algorithm : HLD / Segment Tree
*/
#include<bits/stdc++.h>
using namespace std;

const int MAX = (int)2e9;
#define MAXV 100001
int sz[MAXV], dep[MAXV], par[MAXV], top[MAXV], in[MAXV], out[MAXV], A[MAXV], tr[MAXV*4], inv[MAXV];
vector<int> adj[MAXV];
int num;
int n;
int update(int x, int s, int e, int i, int val) {
	if (i > e || i < s) return tr[x];
	if (s == e) return tr[x] = val;
	return tr[x] = min(update(x * 2, s, (s + e) / 2, i, val), update(x * 2 + 1, (s + e) / 2 + 1, e, i, val));
}
int mi(int x, int s, int e, int l, int r) {
	if (s > r || e < l) return MAX;
	else if (s >= l && e <= r) return tr[x];
	else return min(mi(x * 2, s, (s + e) / 2, l, r), mi(x * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int dfs1(int u, int p) { //make tree
	sz[u] = 1;
	for (auto& v : adj[u]) {
		if (v == p) continue;
		dep[v] = dep[u] + 1; par[v] = u;
		sz[u] += dfs1(v, u); 
		if (sz[v] > sz[adj[u][0]]) swap(v, adj[u][0]);
	}
	return sz[u];
}
void dfs2(int u, int p) { //make hld
	in[u] = ++num;
	inv[num] = u;
	for (int v : adj[u]) {
		if (v == p) continue;
		top[v] = (v == adj[u][0] ? top[u] : v);
		dfs2(v, u);
	}
	out[u] = num;
}
int query(int a, int b) {
	int ret = -1;
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);

		int k = mi(1, 1, n, in[top[a]], in[a]);
		if (k != MAX) ret = inv[k]; 
		a = par[top[a]];
	}
	if (dep[a] > dep[b]) swap(a, b);
	int k = mi(1, 1, n, in[a], in[b]);
	if (k != MAX) ret = inv[k];
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	fill(tr, tr + MAXV * 4, MAX);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs1(1, 1); dfs2(1, 1);
	int m; cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		if (a == 1) {
			if (A[b] == 1) update(1, 1, n, in[b], MAX);
			else update(1, 1, n, in[b], in[b]);
			A[b] ^= 1;
		}
		else {
			cout << query(1, b) << '\n';
		}
	}
}