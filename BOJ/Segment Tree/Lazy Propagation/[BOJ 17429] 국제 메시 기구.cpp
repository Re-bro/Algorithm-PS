/*
	[BOJ 17429] 국제 메시 기구
	Algorithm : HLD / Segment Tree / Lazy propagation
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
#define fi first
#define se second

using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = (1LL << 32);
const int MAX = (int)2e9;
const double PI = acos(-1);

const int V = 505050;
int n, q; 
vector<int> adj[V];
int sz[V], lv[V], par[V], top[V], in[V], out[V], num;
ll tr[2020202], s_lazy[2020202], m_lazy[2020202];
void update_lazy(int x, int s, int e) {
	if (s_lazy[x] != 0 || m_lazy[x] != 1) {
		tr[x] = ((tr[x] * m_lazy[x]) % MOD + ((e - s + 1)*s_lazy[x])%MOD) % MOD;
		tr[x] %= MOD;
		if (s != e) {
			s_lazy[x * 2] = ((s_lazy[x * 2] * m_lazy[x])%MOD + s_lazy[x]) % MOD;
			s_lazy[x * 2 + 1] = ((s_lazy[x * 2 + 1] * m_lazy[x])%MOD + s_lazy[x]) % MOD;
			m_lazy[x * 2] = (m_lazy[x * 2] * m_lazy[x]) % MOD;
			m_lazy[x * 2 + 1] = (m_lazy[x * 2 + 1] * m_lazy[x]) % MOD;
		}
		s_lazy[x] = 0; m_lazy[x] = 1;
	}
}
void update_range(int x, int s, int e, int l, int r, ll a, ll b) {
	update_lazy(x, s, e);
	if (s > r || e < l) return;
	else if (s >= l && e <= r) {
		tr[x] = ((tr[x] * a) % MOD) + ((e - s + 1)*b)%MOD;
		tr[x] %= MOD;
		if (s != e) {
			s_lazy[x * 2] = ((s_lazy[x * 2] * a) % MOD + b) % MOD;
			s_lazy[x * 2 + 1] = ((s_lazy[x * 2 + 1] * a) % MOD + b) % MOD;
			m_lazy[x * 2] = (m_lazy[x * 2] * a) % MOD;
			m_lazy[x * 2 + 1] = (m_lazy[x * 2 + 1] * a) % MOD;
		}
	}
	else {
		update_range(x * 2, s, (s + e) / 2, l, r, a, b);
		update_range(x * 2 + 1, (s + e) / 2 + 1, e, l, r, a, b);
		tr[x] = (tr[x * 2] + tr[x * 2 + 1]) % MOD;
	}
}
ll sum(int x, int s, int e, int l, int r) {
	update_lazy(x, s, e);
	if (s > r || e < l) return 0;
	else if (s >= l && e <= r) return tr[x];
	else return (sum(x * 2, s, (s + e) / 2, l, r) + sum(x * 2 + 1, (s + e) / 2 + 1, e, l, r)) % MOD;
}
void dfs1(int u, int p) {
	sz[u] = 1;
	for (auto &v : adj[u]) {
		if (v == p) continue;
		lv[v] = lv[u] + 1; par[v] = u;
		dfs1(v, u); sz[u] += sz[v];
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
ll query(int x, int y, ll a, ll b, bool flag) {
	ll res = 0;
	while (top[x] != top[y]) {
		if (lv[top[x]] < lv[top[y]]) swap(x, y);
		if (flag) res = (res + sum(1, 1, n, in[top[x]], in[x])) % MOD;
		else update_range(1, 1, n, in[top[x]], in[x], a, b);
		x = par[top[x]];
	}
	if (lv[x] > lv[y]) swap(x, y);
	if (flag) res = (res + sum(1, 1, n, in[x], in[y])) % MOD;
	else update_range(1, 1, n, in[x], in[y], a, b);
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	fill(m_lazy, m_lazy + 2000001, 1);
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs1(1, 1); dfs2(1, 1);
	while (q--) {
		int k; cin >> k;
		int x, y; ll v;
		if (k == 1) {
			cin >> x >> v;
			update_range(1, 1, n, in[x], out[x], 1, v);
		}
		else if (k == 2) {
			cin >> x >> y >> v;
			query(x, y, 1, v, false);
		}
		else if (k == 3) {
			cin >> x >> v;
			update_range(1, 1, n, in[x], out[x], v, 0);
		}
		else if (k == 4) {
			cin >> x >> y >> v;
			query(x, y, v, 0, false);
		}
		else if (k == 5) {
			cin >> x;
			cout << sum(1, 1, n, in[x], out[x])<<'\n';
		}
		else {
			cin >> x >> y;
			cout << query(x, y, 0, 0, true) << '\n';
		}
	}
}