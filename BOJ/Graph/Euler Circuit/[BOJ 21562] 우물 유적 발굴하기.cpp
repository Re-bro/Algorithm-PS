/*
	[BOJ 21562] 우물 유적 발굴하기
	Algorithm : Euler Circuit / Graph
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define pb push_back
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using namespace std;

vector<pii> adj[1010101];
pii ans[1010101];
bool done[2020202];
int n, m, M;
void dfs(int u) {
	while (1) {
		while (!adj[u].empty() && done[adj[u].back().second]) adj[u].pop_back();
		if (adj[u].empty()) break;
		auto [v, idx] = adj[u].back(); adj[u].pop_back();
		done[idx] = true;
		if (idx <= M) ans[idx] = { u, v };
		dfs(v);
	}
}
int main(void) {
	cin >> n >> m;
	M = m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb({ v, i });
		adj[v].pb({ u, i });
	}
	int last = -1, odd = 0;
	for (int i = 1; i <= n; i++) {
		if (sz(adj[i]) % 2) {
			if (last == -1) last = i;
			else {
				adj[last].pb({ i, ++m});
				adj[i].pb({ last, m });
				last = -1;
			}
			odd++;
		}
	}
	cout << (odd == 0 ? 0 : 1) << '\n';

	for (int i = 1; i <= n; i++) dfs(i);
	for (int i = 1; i <= M; i++) {
		cout << ans[i].fi << ' ' << ans[i].se << '\n';
	}
}