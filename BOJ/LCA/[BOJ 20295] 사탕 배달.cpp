/* [BOJ 20295] ���� ���
	Algorithm : LCA

	���� ģ������ ���� ģ���� ������ ���� �濡 �� �� �ִ� ������ ��Ʈ����ũ�� �����صд�.
	�� �� �ִ� ������ ã�� ������ LCA�� log �ð����� Ž���ϸ�, ģ���� ������ ����
	��Ʈ�� �׻� 0���� �ʱ�ȭ�����־�� �Ѵ�.
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