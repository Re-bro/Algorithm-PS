/*
	[BOJ 20647] Cowntagion
	Algorithm : Graph / Tree
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[101010];
ll ans;
void dfs(int u, int p, int d) {
	int cnt = 0;
	for (int v : adj[u]) {
		if (v != p) {
			dfs(v, u, d + 1);
			cnt++;
		}
	}
	for (int i = 0; ; i++) {
		if ((1 << i) >= cnt+1) {
			ans += i;
			ans += cnt;
			break;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1, 0);
	cout << ans;
}