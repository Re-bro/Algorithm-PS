/* [BOJ 15481] �׷����� MST
	Algorithm : Minimum spanning tree / LCA

	����, MST�� �����. �� ����, MST�� �̷�� �������� �̿��ؼ� dfs Ʈ���� ������ش�.
	�� ������ (u, v)��� ����.
	���� (u, v)�� �̹� MST�� �����ϴ� ������ ��쿡�� MST�� ����ġ�� ���� ����ϰ�,
	MST�� �������� �ʴ� �����̶��, �� ������ MST�� �߰��� �� ����Ŭ�� ����� �ȴ�.
	����, ����Ŭ�� �̷�� ���� �� �ش� ������ �����ϰ� ������ ���� �߿��� ����ġ�� ���� ū ������ ��������� �Ѵ�.
	lca(u, v)�� ���ϰ� �Ǹ�, lca(u, v) ~ u / u ~ v / v ~ lca(u, v) �� ��θ� ���� �� ����Ŭ�� ��������Ƿ� 
	u ~ lca(u, v) �� v ~ lca(u, v)������ �ִ� ����ġ ������ ã���ش�.
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