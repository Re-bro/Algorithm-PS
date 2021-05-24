/*
	[BOJ 1135] 뉴스 전하기
	Algorithm : DFS / Graph 
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define pb push_back

using namespace std;
vector<int> adj[51];
int dfs(int u) {
	if (sz(adj[u]) == 0) {
		return 0;
	}
	vector<int> vc;
	for (int v : adj[u]) {
		vc.pb(dfs(v));
	}
	sort(all(vc), greater<int>());
	int mx = 0;
	for (int i = 0; i < sz(vc); i++) {
		mx = max(mx, vc[i] + i + 1);
	}
	return mx;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if(a != -1) adj[a].pb(i);
	}
	cout<<dfs(0);

}