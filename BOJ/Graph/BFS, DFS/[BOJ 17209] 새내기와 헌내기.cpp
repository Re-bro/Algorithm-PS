/*
	[BOJ 17209] 새내기와 헌내기
	Algorithm : Graph / BFS
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

bool diff[2020][2020];
vector<int> adj[2020];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	int n; cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		for (int j = 0; j < n; j++) {
			if (v[i][j] == '1') diff[i + 1][j + 1] = diff[j + 1][i + 1] = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (diff[i][j]) {
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}
	vector<int> color(n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (color[i] > 0) continue;
		int w = 1;
		int b = 0;
		color[i] = 1;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (int v : adj[now]) {
				if (color[v] != 0) continue;
				bool wcan = true;
				for (int u : adj[v]) {
					if (color[u] == 1) wcan = false;
				}
				if (wcan) {
					color[v] = 1;
					w++;
				}
				else {
					color[v] = 2;
					b++;
				}
				q.push(v);
			}
		}
		ans += max(w, b);
	}
	cout << ans;
}