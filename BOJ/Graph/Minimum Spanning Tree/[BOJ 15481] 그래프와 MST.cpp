/* [BOJ 15481] 그래프와 MST
	Algorithm : Minimum spanning tree / LCA

	먼저, MST를 만든다. 그 다음, MST를 이루는 간선들을 이용해서 dfs 트리를 만들어준다.
	각 간선을 (u, v)라고 하자.
	만약 (u, v)가 이미 MST를 구성하는 간선인 경우에는 MST의 가중치의 합을 출력하고,
	MST를 구성하지 않는 간선이라면, 이 간선을 MST에 추가할 때 사이클이 생기게 된다.
	따라서, 사이클을 이루는 간선 중 해당 간선을 제외하고 나머지 간선 중에서 가중치가 가장 큰 간선을 제거해줘야 한다.
	lca(u, v)를 구하게 되면, lca(u, v) ~ u / u ~ v / v ~ lca(u, v) 세 경로를 이을 때 사이클이 만들어지므로 
	u ~ lca(u, v) 와 v ~ lca(u, v)에서의 최대 가중치 간선을 찾아준다.
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
vector<tuple<int, int, int, int>> edge;
vector<pll> adj[200001];
bool in[200001];
int P[200001], par[200001][20], lv[200001], mx[200001][20];
bool cmp(tuple<int, int, int, int> t1, tuple<int, int, int, int> t2) {
	auto[a, b, c, d] = t1;
	auto[e, f, g, h] = t2;
	return c < g;
}
int find(int a) {
	return P[a] < 0 ? a : P[a] = find(P[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (P[a] > P[b]) swap(a, b);
		P[a] += P[b];
		P[b] = a;
		return true;
	}
	return false;
}
void dfs(int u, int p, int level) {
	lv[u] = level;
	for (auto[v, c] : adj[u]) {
		if (v == p) continue;
		dfs(v, u, level + 1);
		par[v][0] = u;
		mx[v][0] = c;
	}
	return;
}
int lca(int x, int y) {
	if (lv[x] > lv[y]) swap(x, y);
	int res = 0;
	for (int i = 19; i >= 0; i--) {
		if (lv[y] - lv[x] >= (1 << i)) {
			res = max(res, mx[y][i]);
			y = par[y][i];
		}
	}
	if (x == y) return res;
	for (int i = 19; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			res = max({ res, mx[x][i], mx[y][i] });
			x = par[x][i];
			y = par[y][i];
		}
	}
	res = max({ res, mx[x][0], mx[y][0] });
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; ll w; cin >> u >> v >> w;
		edge.push_back(make_tuple(u, v, w, i));
	}
	ll ans = 0;
	sort(all(edge), cmp);
	ini(P, -1);
	for (auto [a,b,c,d] : edge) {
		if (merge(a, b)) {
			ans += c;
			in[d] = true;
			adj[a].push_back({ b, c });
			adj[b].push_back({ a, c });
		}
	}
	dfs(1, 1, 0);
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= n; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
			mx[j][i] = max(mx[j][i - 1], mx[par[j][i - 1]][i - 1]);
		}
	}
	vector<ll> res(m);
	for (auto[a, b, c, d] : edge) {
		if (in[d]) res[d] = ans;
		else {
			res[d] = ans + c - lca(a, b);
		}
	}
	for (ll i : res) cout << i << '\n';
}