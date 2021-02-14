/* 
	[BOJ 1761] 정점들의 거리
	Algorithm : LCA
*/
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, par[100001][17], lv[100001];
vector<pii>adj[100001];
int dis[100001][17]; 
int ans = 0;
void dfs(int u, int p, int level) { 
	lv[u] = level; 
	for (pii v : adj[u]) {
		if (v.first == p) continue;
		par[v.first][0] = u;
		dis[v.first][0] = v.second;
		dfs(v.first, u, level + 1);
	}
}
void make_anc() {
	for (int j = 1; j <17; j++) {
		for (int i = 1; i <= N; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			dis[i][j] = dis[par[i][j - 1]][j - 1] + dis[i][j - 1];
		}
	}
}
int lca(int x, int y) { 
	if (lv[x] > lv[y]) swap(x, y);
	for (int i = 16; i >= 0; i--) {
		if (lv[y] - lv[x] >= (1 << i)) {
			ans += dis[y][i];
			y = par[y][i];
		}
	}
	if (x == y) return x;
	for (int i = 16; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			ans += dis[x][i];
			ans += dis[y][i];
			x = par[x][i];
			y = par[y][i];
		}
	}
	ans += dis[x][0] + dis[y][0];
	return par[x][0];
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	dfs(1, 1, 0);
	make_anc();
	int m; cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		ans = 0;
		lca(a, b);
		cout << ans << '\n';
	}
}