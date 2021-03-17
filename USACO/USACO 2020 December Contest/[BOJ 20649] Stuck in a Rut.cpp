/*
	[BOJ 20649] Stuck in a Rut
	Algorithm : Implementation / dfs
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
struct cow {
	int x, y;
	char dir;
};
bool stop[1001];
int nx[1001], ny[1001];
vector<int> adj[1001];
int ans[1001];
int dfs(int u) {
	ans[u] = 0;
	for (int v : adj[u]) {
		ans[u] += dfs(v);
	}
	return ans[u] + 1;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	vector<cow> v;
	for (int i = 0; i < n; i++) {
		char c;  int x, y; cin >> c >> x >> y;
		v.pb({ x, y, c });
	}
	vector<pair<int, pii>>t; //{time, {a, b}} (a stopped b)
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((v[i].dir == 'E' && v[j].dir == 'N' && v[i].x < v[j].x && v[i].y > v[j].y)) {
				if (v[j].x - v[i].x > v[i].y - v[j].y) {
					t.push_back({ v[j].x - v[i].x, {j, i} });
				}
				else if(v[j].x - v[i].x < v[i].y - v[j].y) t.push_back({ v[i].y - v[j].y, {i, j} });
			}
			else if (v[i].dir == 'N' &&v[j].dir == 'E' && v[i].x > v[j].x && v[i].y < v[j].y) {
				if (v[i].x - v[j].x > v[j].y - v[i].y) {
					t.push_back({ v[i].x - v[j].x, {i, j} });
				}
				else if(v[i].x - v[j].x < v[j].y - v[i].y) t.push_back({ v[j].y - v[i].y, {j, i} });
			}
		}
	}
	fill(nx, nx + n, MAX);
	fill(ny, ny + n, MAX);
	sort(all(t));
	
	for (auto[k, q] : t) {
		int a = q.first, b = q.second;
		if (stop[b] || (v[a].dir == 'E'&& nx[a] < v[b].x) || (v[a].dir == 'N' && ny[a] < v[b].y)) continue;
		adj[a].push_back(b);
		stop[b] = true;
		if (v[b].dir == 'E') nx[b] = v[b].x + k;
		else ny[b] = v[b].y + k;
	}
	ini(ans, -1);
	for (int i = 0; i < n; i++) {
		if (ans[i] == -1) dfs(i);
	}
	for (int i = 0; i < n; i++) cout << max(ans[i], 0) << '\n';
}