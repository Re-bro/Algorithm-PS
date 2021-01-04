/* [BOJ 17199] Milk Factory
	Algorithm : DFS / Brute-force

	단방향 간선으로 이루어진 트리가 주어질 때, 
	다른 모든 정점으로부터 현재 정점에 도달할 수 있는 정점 중 가장 번호가 작은 정점을 구한다.
	N이 100이므로 모든 정점에 대해서 dfs를 돌려서 방문하는 정점마다 +1을 해주면, 
	cnt가 N-1인 정점들이 조건을 만족하는 정점이 된다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);
vector<int> adj[101];
int cnt[101];
void dfs(int u, int root) {
	if (u != root) cnt[u]++;
	for (int v : adj[u]) {
		dfs(v, root);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		dfs(i, i);
	}
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == N - 1) return cout << i, 0;
	}
	cout << -1;
}