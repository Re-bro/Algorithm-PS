/*
	[BOJ 20188] 등산 마니아
	Algorithm : Tree DP
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

vector<int> adj[300001];
ll lv[300001], sub[300001];
ll ans = 0;
void dfs(int u, int p, int level) {
	lv[u] = level;
	sub[u] = 1;
	for (int v : adj[u]) {
		if (v != p) {
			dfs(v, u, level + 1);
			sub[u] += sub[v];
		}
	}
}
ll dfs2(int u, int p) {
	ll tmp = 0;
	ll cnt = 0;
	for (int v : adj[u]) {
		if (v == p) continue;
		ll k = dfs2(v, u);
		ans += cnt * (sub[v] * 2 + k) + lv[u]*(cnt*sub[v]) + tmp * sub[v];		
		tmp += k;
		cnt += sub[v];
	}
	ans += (tmp + cnt*(lv[u]+1));
	tmp += sub[u] - 1;
	return tmp;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, 1, 0);
	dfs2(1, 1);
	cout << ans;
}