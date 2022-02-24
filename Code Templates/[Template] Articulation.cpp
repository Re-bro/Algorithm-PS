#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);
int V, E;
vector<vector<int>>adj;
int dfs_n[10001];
bool cut[10001];
int cnt = 0;
/////////////////////////////단절점, 무향 그래프///////////////////////////
int find_cutV(int u, bool isroot) {
	dfs_n[u] = cnt++;
	int ret = dfs_n[u];
	int child = 0;
	for (int v : adj[u]) {
		if (dfs_n[v] == -1) {
			child++;
			int k = find_cutV(v, false);
			if (!isroot && k >= dfs_n[u]) cut[u] = true;
			ret = min(ret, k);
		}
		else ret = min(ret, dfs_n[v]);
	}
	if (isroot) cut[u] = (child >= 2);
	return ret;
}
//////////////////////단절선////////////////////////////
bool visited[100001];
bool finished[100001];
vector<pii> cutedge;
int find_cutE(int u, int p) {
	dfs_n[u] = ++cnt;
	visited[u] = true;
	int ret = dfs_n[u];
	for (int v : adj[u]) {
		int k = MAX;
		if (v == p || finished[v]) continue;
		if (visited[v]) k = min(k, dfs_n[v]);
		else k = min(k, find_cutE(v, u));
		if (k > dfs_n[u]) cutedge.push_back({ min(u, v), max(u, v) });
		ret = min(ret, k);
	}
	finished[u] = true;
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> V >> E;
	adj.assign(V + 1, vector<int>());
	FOR(i, 1, E) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(dfs_n, -1, sizeof(dfs_n));
	FOR(i, 1, V) {
		if (dfs_n[i] == -1) find_cutV(i, true);
	}
	int ans = 0;
	FOR(i, 1, V) {
		if (cut[i]) ans++;
	}
	cout << ans << '\n';
	FOR(i, 1, V) {
		if (cut[i]) cout << i << ' ';
	}
}
