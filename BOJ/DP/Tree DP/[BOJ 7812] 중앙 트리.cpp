/* [BOj 7812] 중앙 트리
	Algorithm : Tree DP
	
	설명 : https://wogud6792.tistory.com/90
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using ll = long long;
using pii = pair<int, int>;
vector<vector<pii>>adj;
ll dis[10001];
int sub[10001];
int n;
ll init(int u, int p) {
	sub[u] = 1;
	dis[u] = 0;
	for (pii v : adj[u]) {
		if (v.first == p) continue;
		dis[u] += init(v.first, u);
		dis[u] += v.second*sub[v.first];
		sub[u] += sub[v.first];
	}
	return dis[u];
}
void sol(int u, int p) {
	for (pii v : adj[u]) {
		if (v.first == p) continue;
		dis[v.first] = dis[u] + (n - 2 * sub[v.first])*v.second;
		sol(v.first, u);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	while (1) {
		cin >> n;
		if (n == 0) break;
		ini(dis, 0);
		adj.assign(n + 1, vector<pii>());
		for (int i = 1; i < n; i++) {
			int a, b, c; cin >> a >> b >> c;
			a++; b++;
			adj[a].push_back({ b, c });
			adj[b].push_back({ a, c });
		}
		init(1, 1);
		sol(1, 1);
		ll ans =1e18;
		for (int i = 1; i <= n; i++) ans = min(ans, dis[i]);
		cout << ans << '\n';
	}
}