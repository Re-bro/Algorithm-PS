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
struct hopcroft_karp {
	int n;
	vector<int> A, B, dist, match, see;
	vector<vector<int>>adj;
	hopcroft_karp(int n) : n(n) {
		A.assign(n + 1, -1);
		B.assign(n + 1, -1);
		dist.assign(n + 1, 0);
		match.assign(n + 1, 0);
		adj.resize(n + 1);
	}
	void addedge(int u, int v) {
		adj[u].push_back(v);
	}
	void bfs() {
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (!match[i]) {
				dist[i] = 0;
				q.push(i);
			}
			else dist[i] = MAX;
		}
		while (!q.empty()) {
			int a = q.front(); q.pop();
			for (int b : adj[a]) {
				if (B[b] != -1 && dist[B[b]] == MAX) {
					dist[B[b]] = dist[a] + 1;
					q.push(B[b]);
				}
			}
		}
	}
	bool dfs(int u) {
		for (; see[u] < (int)adj[u].size(); see[u]++) {
			int v = adj[u][see[u]];
			if (B[v] == -1 || (dist[B[v]] == dist[u] + 1 && dfs(B[v]))) {
				match[u] = true;
				A[u] = v;
				B[v] = u;
				return true;
			}
		}
		return false;
	}
	int solve() {
		int ret = 0;
		while (1) {
			see.assign(n + 1, 0);
			bfs();
			int flow = 0;
			for (int i = 1; i <= n; i++) {
				if (!match[i] && dfs(i)) flow++;
			}
			if (!flow) break;
			ret += flow;
		}
		return ret;
	}
};
vector<pii> v[200001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		v[i].push_back({ a, b });
		v[i].push_back({ c, d });
	}
	int s = 0;
	int e = 1000000;
	int ans = MAX;
	while (s <= e) {
		int mid = (s + e) / 2;
		hopcroft_karp hk(2 * n);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 2; j++) {
				if (v[i][j].second <= mid) hk.addedge(i, v[i][j].first);
			}
		}
		if (hk.solve() == n) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	if (ans == MAX) cout << -1;
	else cout << ans;
}