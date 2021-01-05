/* [CF 1153D] Serval and Rooted Tree
	Algorithm : greedy / tree / dfs / dp

	Ç®ÀÌ : https://wogud6792.tistory.com/100
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;
vector<int>adj[300001];
int flag[300001];
int leaf = 0;
int dfs(int u) {
	if (sz(adj[u]) == 0) {
		leaf++;
		return 0;
	}
	int res = (flag[u]? 1e6 : 0);
	for (int v : adj[u]) {
		if (flag[u]) res = min(res, dfs(v));
		else res += dfs(v);
	}
	return (flag[u] ? res : res + sz(adj[u])-1);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> flag[i];
	for (int i = 1; i < n; i++) {
		int a; cin >> a;
		adj[a].push_back(i + 1);
	}
	int k = dfs(1);
	cout << leaf - k;
}