/* [BOJ 20295] 사탕 배달
	Algorithm : LCA

	현재 친구에서 다음 친구를 만나러 가는 길에 살 수 있는 사탕을 비트마스크로 저장해둔다.
	살 수 있는 사탕을 찾는 과정을 LCA로 log 시간내에 탐색하며, 친구를 만나고 나면
	비트를 항상 0으로 초기화시켜주어야 한다.
*/
#include<bits/stdc++.h>
using namespace std;
int n, now;
vector<int> adj[100001];
int C[100001], f[100001], like[100001], lv[100001], par[100001][20], have[100001][20];
void dfs(int u, int p, int level) {
	lv[u] = level;
	for (int v : adj[u]) {
		if (v == p) continue;
		par[v][0] = u;
		have[v][0] |= (1 << C[u]);
		dfs(v, u, level+1);
	}
}
void lca(int x, int y) {
	if (lv[x] > lv[y]) swap(x, y);
	for (int i = 19; i >= 0; i--) {
		if (lv[y] - lv[x] >= (1 << i)) {
			now |= have[y][i];
			y = par[y][i];
		}
	}
	if (x == y) return;
	for (int i = 19; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			now |= have[x][i];
			now |= have[y][i];
			x = par[x][i];
			y = par[y][i];
		}
	}
	now |= have[x][0];
	now |= have[y][0];
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> C[i];
		now |= (1 << C[i]);
	}
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int m; cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> f[i] >> like[i];
	}
	dfs(1, 1, 0);
	for (int k = 1; k < 20; k++) {
		for (int i = 1; i <= n; i++) {
			par[i][k] = par[par[i][k - 1]][k - 1];
			have[i][k] |= (have[par[i][k - 1]][k - 1] | have[i][k - 1]);
		}
	}
	if (now & (1 << like[1])) 	cout << "PLAY\n";
	else cout << "CRY\n";
	for (int i = 2; i <= m; i++) {
		now = 0;
		lca(f[i - 1], f[i]);
		now |= (1 << C[f[i - 1]]);
		now |= (1 << C[f[i]]);
		if (now & (1 << like[i])) cout << "PLAY\n";
		else cout << "CRY\n";
	}
}