/*
	[BOJ 21566] 트리 정리하기
	Algorithm : Constructive / DFS / Ad-hoc
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);

using namespace std;

set<int> adj[1010];
vector<int> tmp;
vector<tuple<int, int, int, int>> ans;
bool chk;
void dfs(int u, int p, int cnt) {
	if (chk) return;
	if (cnt == 4) {
		int a = tmp[0];
		int b = tmp[1];
		int c = tmp[2];
		int d = tmp[3];
		adj[a].erase(b); adj[b].erase(a);
		adj[b].erase(c); adj[c].erase(b);
		adj[c].erase(d); adj[d].erase(c);
		adj[a].insert(c); adj[c].insert(a);
		adj[b].insert(d); adj[d].insert(b);
		adj[a].insert(d); adj[d].insert(a);
		ans.pb(make_tuple(a, b, c, d));
		chk = true;
		return;
	}
	for (auto v : adj[u]) {
		if (v == p) continue;
		tmp.pb(v);
		dfs(v, u, cnt + 1);
		tmp.pop_back();
		if (chk) return;
	}
}
int main(void) {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	while (1) {
		chk = false;
		tmp.clear();
		tmp.pb(1);
		dfs(1, 1, 1);
		if (!chk) break;
	}
	cout << sz(ans) << '\n';
	for (auto [a, b, c, d] : ans) {
		cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	}
}