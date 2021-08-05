/*
	[BOJ 17399] 트리의 외심
	Algorithm : LCA
*/

#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> adj[101010];
int par[101010][18], lv[101010];
void dfs(int u, int p, int dep) {
	lv[u] = dep;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u, dep + 1);
		par[v][0] = u;
	}
}
int dis(int a, int b) {
	int ret = 0;
	if (lv[a] > lv[b]) swap(a, b);
	for (int i = 17; i >= 0; i--) {
		if (lv[b] - lv[a] >= (1 << i)) {
			b = par[b][i];
			ret += (1 << i);
		}
	}
	if (a == b) return ret;
	for (int i = 17; i >= 0; i--) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
			ret += (1 << i) * 2;
		}
	}
	ret += 2;
	return ret;
}
int sol(int x, int y, int z) {
	int d = dis(x, y);
	if (d % 2) return -1;
	d /= 2;
	int tmp = d;
	if (lv[x] < lv[y]) swap(x, y);
	for (int i = 17; i >= 0; i--) {
		if (tmp >= (1 << i)) {
			x = par[x][i];
			tmp -= (1 << i);
		}
	}
	if (dis(x, z) == d) return x;
	else return -1;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1, 1, 0);
	for (int j = 1; j <= 17; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
	int q; cin >> q;
	while (q--) {
		int a, b, c; cin >> a >> b >> c;
		cout << max({ sol(a, b, c), sol(a, c, b), sol(b, c, a) }) << '\n';
	}
}