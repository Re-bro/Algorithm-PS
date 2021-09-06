#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MAX = (int)1e9;

int sub[202020];
vector<pii> adj[202020];
bool visited[202020];
int min_depth[1010101];
vector<int> tmp;
int n, k;
int get_size(int u, int p) {
	sub[u] = 1;
	for (auto [v, d] : adj[u]) {
		if (v == p || visited[v]) continue;
		sub[u] += get_size(v, u);
	}
	return sub[u];
}
int get_cent(int u, int p, int size) {
	for (auto [v, d] : adj[u]) {
		if (v == p || visited[v]) continue;
		if (sub[v] > size) return get_cent(v, u, size);
	}
	return u;
}
int sol(int u, int p, int dis, int dep) { // through centroid
	int ret = MAX;
	if (dis > k) return ret;
	ret = min(ret, min_depth[k - dis] + dep);
	for (auto [v, d] : adj[u]) {
		if (visited[v] || v == p) continue;
		ret = min(ret, sol(v, u, dis + d, dep + 1));
	}
	return ret;
}
void update(int u, int p, int dis, int dep) {
	if (dis > k) return;
	min_depth[dis] = min(min_depth[dis], dep);
	tmp.push_back(dis);
	for (auto [v, d] : adj[u]) {
		if (visited[v] || v == p) continue;
		update(v, u, dis + d, dep + 1);
	}
}
int dnc(int u) {
	int cent = get_cent(u, u, get_size(u, u) / 2);
	visited[cent] = true;
	int ret = MAX;
	for (int i : tmp) min_depth[i] = MAX;
	min_depth[0] = 0;
	tmp.clear();
	for (auto [v, d] : adj[cent]) {
		if (visited[v]) continue;
		ret = min(ret, sol(v, cent, d, 1));
		update(v, cent, d, 1);
	}
	for (auto [v, d] : adj[cent]) {
		if (visited[v]) continue;
		ret = min(ret, dnc(v));
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v, l; cin >> u >> v >> l;
		adj[u].push_back({ v, l });
		adj[v].push_back({ u, l });
	}
	fill(min_depth, min_depth + 1000001, MAX);
	int ans = dnc(0);
	if (ans == MAX) cout << -1;
	else cout << ans;
}