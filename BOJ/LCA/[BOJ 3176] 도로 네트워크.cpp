/* [BOJ 3176] 도로 네트워크
	Algorithm : LCA
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

int n;
vector<pii> adj[100001];
int lv[100001];
int par[100001][20];
pii dis[100001][20];
void dfs(int u, int p, int l) {
	lv[u] = l;
	for (auto [v, c] : adj[u]) {
		if (v == p) continue;
		par[v][0] = u;
		dis[v][0] = { c, c };
		dfs(v, u, l + 1);
	}
}
void make_anc() {
	for (int k = 1; k < 20; k++) {
		for (int i = 1; i <= n; i++) {
			par[i][k] = par[par[i][k - 1]][k - 1];
			dis[i][k].fi = min(dis[i][k - 1].fi, dis[par[i][k - 1]][k - 1].fi);
			dis[i][k].se = max(dis[i][k - 1].se, dis[par[i][k - 1]][k - 1].se);
		}
	}
}
pii lca(int x, int y) {
	int mi = MAX;
	int mx = 0;
	if (lv[x] > lv[y]) swap(x, y);
	for (int i = 19; i >= 0; i--) {
		if (lv[y] - lv[x] >= (1 << i)) {
			mi = min(mi, dis[y][i].fi);
			mx = max(mx, dis[y][i].se);
			y = par[y][i];
		}
	}
	if (x == y) return { mi, mx };
	for (int i = 19; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			mi = min({ mi, dis[x][i].fi, dis[y][i].fi });
			mx = max({ mx, dis[x][i].se, dis[y][i].se });
			x = par[x][i];
			y = par[y][i];
		}
	}
	mi = min({ mi, dis[x][0].fi, dis[y][0].fi });
	mx = max({ mx, dis[x][0].se, dis[y][0].se });
	return { mi, mx };
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	dfs(1, 1, 0);
	make_anc();
	int K; cin >> K;
	while (K--) {
		int a, b; cin >> a >> b;
		auto [i, j] = lca(a, b);
		cout << i << ' ' << j << '\n';
	}
}