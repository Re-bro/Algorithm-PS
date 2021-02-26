/*
	[BOJ 13309] Æ®¸®
	Algorithm : HLD / Segment Tree

*/
#include<bits/stdc++.h>
using namespace std;

int n, q;
#define MAXV 200001
int sz[MAXV], dep[MAXV], par[MAXV], top[MAXV], in[MAXV], out[MAXV], tr[MAXV * 4];
vector<int> adj[MAXV];
int num;
void update(int x, int s, int e, int i, int val) {
	if (i > e || i < s) return;
	tr[x] += val;
	if (s != e) {
		update(x * 2, s, (s + e) / 2, i, val);
		update(x * 2 + 1, (s + e) / 2 + 1, e, i, val);
	}
}
int sum(int x, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	else if (s >= l && e <= r) return tr[x];
	else return sum(x * 2, s, (s + e) / 2, l, r) + sum(x * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
void dfs1(int u) {
	sz[u] = 1;
	for (auto &v : adj[u]) {
		dep[v] = dep[u] + 1; par[v] = u;
		dfs1(v); sz[u] += sz[v];
		if (sz[v] > sz[adj[u][0]]) swap(v, adj[u][0]);
	}
}
void dfs2(int u) { //make hld
	in[u] = ++num;
	for (int v : adj[u]) {
		top[v] = (v == adj[u][0] ? top[u] : v);
		dfs2(v);
	}
	out[u] = num;
}
int query(int a, int b) {
	int ret = 0;
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		ret += sum(1, 1, n, in[top[a]], in[a]);
		a = par[top[a]];
	}
	if (dep[a] > dep[b]) swap(a, b);
	else if (dep[a] == dep[b]) return ret;
	a = adj[a][0];
	ret += sum(1, 1, n, in[a], in[b]);
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int a; cin >> a;
		adj[a].push_back(i + 1);
	}
	dfs1(1); dfs2(1);
	while (q--) {
		int b, c, d; cin >> b >> c >> d;
		if (query(b, c) == 0) {
			cout << "YES\n";
			if (d == 1) {
				update(1, 1, n, in[b], 1);
			}
		}
		else {
			cout << "NO\n";
			if (d == 1) {
				update(1, 1, n, in[c], 1);
			}
		}
	}
}