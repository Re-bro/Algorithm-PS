/*
	[BOJ 2861] 원섭동 사람들
	Algorithm : Graph / Topological sort
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

vector<pii> adj[202020];
int in[202020];
int pay[202020];
int have[202020];
bool chk[202020];
int idx, mi;
int ans = 0;
void dfs(int u, int s) {
	if (mi > pay[u] - have[u]) {
		mi = pay[u] - have[u];
		idx = u;
	}
	for (auto [v, c] : adj[u]) {
		if (v == s) continue;
		dfs(v, s);
	}
}
void dfs2(int u, int s) {
	chk[u] = true;
	for (auto [v, c] : adj[u]) {
		have[v] += c;
		if (pay[v] - have[v] > 0) ans += pay[v] - have[v];
		if(v != s) dfs2(v, s);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		adj[i].pb({ a, b });
		in[a]++;
		pay[i] = b;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int now = q.front(); q.pop();
		chk[now] = true;
		ans += max(0, pay[now] - have[now]);
		for (auto [v, c] : adj[now]) {
			have[v] += c;
			in[v]--;
			if (in[v] == 0) q.push(v);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			mi = MAX;
			dfs(i, i);
			ans += max(0, pay[idx] - have[idx]);
			dfs2(idx, idx);
		}
	}
	cout << ans;
}