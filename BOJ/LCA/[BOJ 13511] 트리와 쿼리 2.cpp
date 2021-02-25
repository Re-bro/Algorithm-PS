/* 
	[BOJ 13511] Æ®¸®¿Í Äõ¸® 2
	Algorithm : LCA / Sparse Table

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

vector<pair<int, ll>> adj[100001];
int par[100001][18], lv[100001];
ll dis[100001][18];
int n;
void dfs(int u, int p, int level) {
	lv[u] = level;
	for (auto [v, c] : adj[u]) {
		if (v == p) continue;
		dfs(v, u, level + 1);
		par[v][0] = u;
		dis[v][0] = c;
	}
}
void make_anc() {
	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= n; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
			dis[j][i] = dis[j][i - 1] + dis[par[j][i - 1]][i - 1];
		}
	}
}
ll qry(int x, int y, int k) {
	ll res = 0;
	int X = x, Y = y;
	bool chk = false;
	if (lv[x] > lv[y]) {
		swap(x, y);
		chk = true;
	}
	int lenx = 0;
	int leny = 0;
	for (int i = 17; i >= 0; i--) {
		if (lv[y] - lv[x] >= (1 << i)) {
			res += dis[y][i];
			y = par[y][i];
			if (chk) lenx += (1 << i);
			else leny += (1 << i);
		}
	}
	if (x == y) {
		if (k == -1) return res;
		int from;
		if (lv[X] > lv[Y]) from = X;
		else {
			from = Y;
			k = lv[Y] - lv[X] - k;
		}
		for (int i = 17; i >= 0; i--) {
			if (k >= (1 << i)) {
				k -= (1 << i);
				from = par[from][i];
			}
		}
		return from;
	}
	for (int i = 17; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			res += dis[x][i];
			res += dis[y][i];
			x = par[x][i];
			y = par[y][i];
			lenx += (1 << i);
			leny += (1 << i);
		}
	}
	lenx++; leny++;
	if (k == -1) {
		res += dis[x][0];
		res += dis[y][0];
		return res;
	}
	else {
		if (lenx == k) return par[x][0];
		else if (lenx < k) {
			int to = leny - (k - lenx);
			for (int i = 17; i >= 0; i--) {
				if (to >= (1 << i)) {
					to -= (1 << i);
					Y = par[Y][i];
				}
			}
			return Y;
		}
		else {
			for (int i = 17; i >= 0; i--) {
				if (k >= (1 << i)) {
					k -= (1 << i);
					X = par[X][i];
				}
			}
			return X;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; ll w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
	dfs(1, 1, 0);
	make_anc();
	int m; cin >> m;
	for (int i = 1; i <= m; i++) {
		int a; cin >> a;
		if (a == 1) {
			int b, c; cin >> b >> c;
			cout << qry(b, c, -1) << '\n';
		}
		else {
			int b, c, d; cin >> b >> c >> d;
			if (b == c) cout << b << '\n';
			else	cout << qry(b, c, d - 1) << '\n';
		}
	}
}