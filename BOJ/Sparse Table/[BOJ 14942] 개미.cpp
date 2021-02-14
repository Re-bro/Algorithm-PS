/* [BOJ 14942] 개미
	Algorithm : BFS / Tree / Sparse Matrix

	주어지는 그래프는 트리이다. 
	1번방으로부터 각 방까지의 거리를 저장해두고, 각 방에서 1번방까지 올라가는데,
	단순히 부모만 타고 올라간다면 시간이 오래 걸린다.
	따라서 LCA처럼 희소 배열을 만들어서 현재 남은 에너지로 갈 수 있는 최대한 먼 2^k번째 조상으로 올라간다.
	그러면 logn만에 루트에 가장 가까운 방으로 올라갈 수 있다.
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