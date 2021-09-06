/*
	[BOJ 20297] Confuzzle
	Algorithm : Centroid Decomposition
*/

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int MAX = (int)1e9;

vector<int> adj[101010];
bool visited[101010];
int sub[101010];
int c[101010];
vector<int> tmp;
int min_dis[101010];
int get_size(int u, int p) {
	sub[u] = 1;
	for (int v : adj[u]) {
		if (v == p || visited[v]) continue;
		sub[u] += get_size(v, u);
	}
	return sub[u];
}
int get_cent(int u, int p, int size) {
	for (int v : adj[u]) {
		if (v == p || visited[v]) continue;
		if (sub[v] > size) return get_cent(v, u, size);
	}
	return u;
}
int sol(int u, int p, int dis) {
	int ret = MAX;
	ret = min(ret, min_dis[c[u]] + dis);
	for (int v : adj[u]) {
		if (visited[v] || v == p) continue;
		ret = min(ret, sol(v, u, dis + 1));
	}
	return ret;
}
void update(int u, int p, int dis) {
	tmp.pb(c[u]);
	min_dis[c[u]] = min(min_dis[c[u]], dis);
	for (int v : adj[u]) {
		if (v == p || visited[v]) continue;
		update(v, u, dis + 1);
	}
}
int dnc(int u) {
	int cent = get_cent(u, u, get_size(u, u) / 2);
	visited[cent] = true;
	for (int i : tmp) min_dis[i] = MAX;
	tmp.clear();
	min_dis[c[cent]] = 0;
	tmp.pb(c[cent]);
	int ret = MAX;
	for (int v : adj[cent]) {
		if (visited[v]) continue;
		ret = min(ret, sol(v, cent, 1));
		update(v, cent, 1);
	}
	for (int v : adj[cent]) {
		if (visited[v]) continue;
		ret = min(ret, dnc(v));
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	fill(min_dis, min_dis + 100001, MAX);
	cout << dnc(1);
}