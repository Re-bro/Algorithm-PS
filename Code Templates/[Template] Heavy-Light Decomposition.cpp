/*
	[Template] Heavy-Light Decomposition
	Explanation : https://justicehui.github.io/hard-algorithm/2020/01/24/hld/

	[ in[top[v]], in[v] ] = interval of v and top[v]
*/

#include<bits/stdc++.h>
using namespace std;
//sz[i] = size of subtree with i as root
//dep[i] = depth of i
//par[i] = parent of i
//top[i] = top vertex of the chain to which i belongs
//in[i], out[i] = dfs number

#define MAXV 100001
int sz[MAXV], dep[MAXV], par[MAXV], top[MAXV], in[MAXV], out[MAXV];
vector<int> adj[MAXV];
int num;
void dfs1(int u) { //make tree
	sz[u] = 1;
	for (auto& v : adj[u]) {
		dep[v] = dep[u] + 1; par[v] = u;
		dfs1(v); sz[u] += sz[v];
		if (sz[v] > sz[adj[u][0]]) swap(v, adj[u][0]);
	}
}
void dfs2(int u) { //make hld
	in[u] = ++num;
	for (int v : adj[u]) {
		top[v] = (v == adj[u][0] ? top[u] : v);
		dfs2(v);
	}
	out[u] = num;
}

int query(int a, int b) {
	int ret = 0;
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		int st = top[a];
		ret += seg.query(in[top[a]], in[a]); //segtree range query [in[top[a]], in[a]]
		a = par[top[a]];
	}
	if (dep[a] > dep[b]) swap(a, b);
	ret += seg.query(in[a], in[b]); //segtree range query [in[a], in[b]]
	return ret;
	if (dep[a] > dep[b]) swap(a, b);
	
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
}