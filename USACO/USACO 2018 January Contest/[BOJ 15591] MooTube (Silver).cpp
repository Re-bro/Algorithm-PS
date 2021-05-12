/*
	[BOJ 15591] MooTube (Silver)
	Algorithm : Graph / DFS
*/
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using pii = pair<int, int>;
const int MAX = (int)2e9;

vector<pii> adj[5050];
int dfs(int u, int p, int val, int k) {
	int res = 0;
	if (val >= k && val != MAX) res++;
	for (auto[v, c] : adj[u]) {
		if (v == p) continue;
		res += dfs(v, u, min(val, c), k);
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, q; cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int p, q, r; cin >> p >> q >> r;
		adj[p].pb({ q, r });
		adj[q].pb({ p, r });
	}
	while (q--) {
		int k, v; cin >> k >> v;
		cout<<dfs(v, v, MAX, k)<<'\n';
	}
}