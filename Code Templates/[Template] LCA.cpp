/* 
	[Template] Lowest Common Ancestor
	O(logn) for query
*/

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int N, par[100001][21], lv[100001];
vector<vector<pii>>adj;
int dis[100001][21]; //거리 구할 때
int ans = 0;
void dfs(int u, int p, int level) { //전처리
	lv[u] = level; //level은 0부터 시작
	for (pii v : adj[u]) {
		if (v.first == p) continue;
		par[v.first][0] = u;
		dis[v.first][0] = v.second;
		dfs(v.first, u, level + 1);
	}
}
void make_anc() { //조상들 만들기
	for (int j = 1; j <= 20; j++) {
		for (int i = 1; i <= N; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			dis[i][j] = dis[par[i][j - 1]][j - 1] + dis[i][j - 1];
		}
	}
}
int lca(int x, int y) { //LCA 구하기
	if (lv[x] > lv[y]) swap(x, y);
	for (int i = 20; i >= 0; i--) {
		if (lv[y] - lv[x] >= (1 << i)) {
			ans += dis[y][i];
			y = par[y][i];
		}
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; i--) {
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