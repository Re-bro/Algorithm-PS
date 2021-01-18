/* [BOJ 8992] 집기 게임
	Algorithm : MCMF

	source와 가로선을, sink와 세로선을 연결하고, 
	가로선과 교점을 가지는 세로선에 모두 간선을 연결해준다.
	비용은 두 선분의 무게의 곱에 -를 붙여 최댓값을 구할 수 있도록 해준다. 
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
#define MAX_V 410
int N, M;
int S, T;
int c[MAX_V][MAX_V]; //각 간선의 용량
int d[MAX_V][MAX_V]; //각 간선의 비용
int f[MAX_V][MAX_V]; //각 간선에 흐르는 유량
vector<int> adj[410];
struct line {
	int x, y, x2, y2, w;
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int tc;  cin >> tc;
	while (tc--) {
		int n, m; cin >> n >> m;
		ini(c, 0); ini(d, 0); ini(f, 0);
		for (int i = 0; i < 410; i++) adj[i].clear();
		S = 0;
		T = 401;
		vector<line> garo, sero;
		for (int i = 1; i <= n; i++) {
			int a, b, c, d; cin >> a >> b >> c >> d;
			if (a > c) swap(a, c);
			int e; cin >> e;
			garo.push_back({ a, b, c, d, e });
		}
		for (int i = 1; i <= m; i++) {
			int a, b, c, d; cin >> a >> b >> c >> d;
			if (b > d) swap(b, d);
			int e; cin >> e;
			sero.push_back({ a,b,c,d, e });
		}
		for (int i = 0; i < n; i++) {
			c[S][i + 1] = 1;
			adj[S].push_back(i + 1);
			adj[i + 1].push_back(S);
			for (int j = 0; j < m; j++) {
				if (i == 0) {
					c[201 + j][T] = 1;
					adj[201 + j].push_back(T);
					adj[T].push_back(201 + j);
				}
				if (sero[j].x > garo[i].x && sero[j].x < garo[i].x2 && garo[i].y > sero[j].y && garo[i].y < sero[j].y2) {
					c[i + 1][201 + j] = 1;
					adj[i + 1].push_back(201 + j);
					adj[201 + j].push_back(i + 1);
					d[i + 1][201 + j] = -garo[i].w * sero[j].w;
					d[201 + j][i + 1] = garo[i].w * sero[j].w;
				}
			}
		}
		int ans = 0;
		int mincost = 0;
		while (1) {
			vector<int> P(MAX_V, -1), dis(MAX_V, MAX), inQ(MAX_V);
			//SPFA
			queue<int> q;
			dis[S] = 0;
			inQ[S] = 1;
			q.push(S);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				inQ[u] = false;
				for (int v : adj[u]) {
					if (c[u][v] - f[u][v] > 0 && dis[v] > dis[u] + d[u][v]) {
						dis[v] = dis[u] + d[u][v];
						P[v] = u;
						if (!inQ[v]) {
							q.push(v);
							inQ[v] = 1;
						}
					}
				}
			}
			if (P[T] == -1) break;
			int flow = MAX;
			for (int i = T; i != S; i = P[i]) {
				flow = min(flow, c[P[i]][i] - f[P[i]][i]);
			}
			for (int i = T; i != S; i = P[i]) {
				mincost += flow * d[P[i]][i];
				f[P[i]][i] += flow;
				f[i][P[i]] -= flow;
			}
			ans += flow;
		}
		cout << ans << ' ' << -mincost << '\n';
	}

}