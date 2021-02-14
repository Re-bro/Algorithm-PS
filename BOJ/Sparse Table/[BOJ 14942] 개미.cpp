/* [BOJ 14942] ����
	Algorithm : BFS / Tree / Sparse Matrix

	�־����� �׷����� Ʈ���̴�. 
	1�������κ��� �� ������� �Ÿ��� �����صΰ�, �� �濡�� 1������� �ö󰡴µ�,
	�ܼ��� �θ� Ÿ�� �ö󰣴ٸ� �ð��� ���� �ɸ���.
	���� LCAó�� ��� �迭�� ���� ���� ���� �������� �� �� �ִ� �ִ��� �� 2^k��° �������� �ö󰣴�.
	�׷��� logn���� ��Ʈ�� ���� ����� ������ �ö� �� �ִ�.
*/
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n;
int e[100001];
int par[100001][18];
int dis[100001][18];
vector<pii> adj[100001];
void dfs(int u, int p) {
	for (auto [v, c] : adj[u]) {
		if (v == p) continue;
		par[v][0] = u;
		dis[v][0] = c;
		dfs(v, u);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> e[i];
	for (int i = 1; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a, c });
	}
	dfs(1, 1);
	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= n; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
			dis[j][i] = dis[par[j][i - 1]][i - 1] + dis[j][i - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		int now = i;
		for (int j = 17; j >= 0; j--) {
			if (dis[now][j] <= e[i]) {
				e[i] -= dis[now][j];
				now = par[now][j];
			}
		}
		if (now == 0) now = 1;
		cout << now << '\n';
	}
}