/*
	[BOJ 11932] 트리와 K번째 수
	Algorithm : PBS / HLD / Segment Tree
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

int a[101010], tr[101010];
vector<int> adj[101010];
int val[101010];
int sz[101010], dep[101010], par[101010], top[101010], in[101010], out[101010];
int num, n, m;
int L[101010], R[101010], ans[101010];
vector<int> g[101010];
struct qry {
	int x, y, k;
};
qry q[101010];
void update(int i) {
	while (i <= n) {
		tr[i]++;
		i += (i & -i);
	}
}
int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += tr[i];
		i -= (i & -i);
	}
	return res;
}
void dfs1(int u, int p) {
	sz[u] = 1;
	for (auto& v : adj[u]) {
		if (v == p) continue;
		dep[v] = dep[u] + 1;
		par[v] = u;
		dfs1(v, u);
		sz[u] += sz[v];
		if (sz[v] > sz[adj[u][0]]) swap(v, adj[u][0]);
	}
}
void dfs2(int u, int p) {
	in[u] = ++num;
	for (int v : adj[u]) {
		if (v == p) continue;
		top[v] = (v == adj[u][0] ? top[u] : v);
		dfs2(v, u);
	}
	out[u] = num;
}
int query(int x, int y) {
	int cnt = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		cnt += sum(in[x]) - sum(in[top[x]] - 1);
		x = par[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	cnt += sum(in[y]) - sum(in[x] - 1);
	return cnt;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	vector<int> v;
	for (int i = 1; i <= n; i++) cin >> a[i], v.pb(a[i]);
	sort(all(v));
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
		val[a[i]] = i;
	}
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs1(1, 1);
	dfs2(1, 1);
	for (int i = 1; i <= m; i++) {
		cin >> q[i].x >> q[i].y >> q[i].k;
		L[i] = 1;
		R[i] = n;
		ans[i] = MAX;
	}
	while (1) {
		bool chk = false;
		for (int i = 1; i <= n; i++) g[i].clear();
		ini(tr, 0);
		for (int i = 1; i <= m; i++) {
			if (L[i] <= R[i]) {
				g[(L[i] + R[i]) / 2].pb(i);
				chk = true;
			}
		}
		if (!chk) break;
		for (int i = 1; i <= n; i++) {
			update(in[val[i]]);
			for (int j : g[i]) {
				if (query(q[j].x, q[j].y) >= q[j].k) {
					R[j] = i - 1;
					ans[j] = min(ans[j], i);
				}
				else L[j] = i + 1;
			}
		}
	}
	for (int i = 1; i <= m; i++) cout << v[ans[i] - 1] << '\n';
}