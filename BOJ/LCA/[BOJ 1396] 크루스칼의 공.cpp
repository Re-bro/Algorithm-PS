/*
	[BOJ 1396] 크루스칼의 공
	Algorithm : Union-find / LCA
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
using namespace std;

int n, m, q;
vector<int> adj[202020];
int par[202020][19], lv[202020], P[202020], w[202020], s[202020];
int find(int a) {
	return P[a] < 0 ? a : P[a] = find(P[a]);
}
void dfs(int u, int p, int level) {
	lv[u] = level;
	for (int v : adj[u]) {
		if (v == u) continue;
		par[v][0] = u;
		dfs(v, u, level + 1);
	}
}
int lca(int x, int y) {
	if (lv[x] > lv[y]) swap(x, y);
	for (int i = 18; i >= 0; i--) {
		if (lv[y] - lv[x] >= (1 << i)) {
			y = par[y][i];
		}
	}
	if (x == y) return x;
	for (int i = 18; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			x = par[x][i];
			y = par[y][i];
		}
	}
	return par[x][0];
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	vector<tuple<int, int, int>> edge;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge.pb(make_tuple(c, a, b));
	}
	sort(all(edge));
	memset(P, -1, sizeof(P));
	for (int i = 1; i <= n; i++) s[i] = 1;
	for (auto [c, a, b] : edge) {
		a = find(a); b = find(b);
		if (a != b) {
			adj[++n].pb(a);
			adj[n].pb(b);
			P[a] = n;
			P[b] = n;
			w[n] = c;
			s[n] = s[a] + s[b];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (P[i] < 0) dfs(i, i, 0);
	}
	for (int j = 1; j <=18; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
	cin >> q;
	while (q--) {
		int x, y; cin >> x >> y;
		if (find(x) != find(y)) cout << -1 << '\n';
		else {
			int L = lca(x, y);
			cout << w[L] << ' ' << s[L] << '\n';
		}
	}
}