/* [BOJ 11493] 동전 교환
	Algorithm : MCMF

	그래프에 주어지는 간선들을 모두 비용이 1이고 용량은 무한이 되도록 저장한다.
	현재 동전의 색과 정점의 색이 다른 정점들만 변경이 필요하므로, 
	source와 검정색 동전 & 흰 정점 인 정점들을 연결하고, 
	sink와 흰 동전 & 검정색 정점을 연결해준다. 
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

#define MAX_V 510
int S, T;
struct MCMF {
	struct edge {
		int to, c, f, d;
		edge *rev;
		edge(int to, int c, int d, int f) : to(to), c(c), d(d), f(f) {}
		void addflow(int flow) {
			f += flow;
			rev->f -= flow;
		}
		int spare() {
			return c - f;
		}
	};
	vector<edge*>adj[MAX_V];
	vector<int> P;
	vector<edge*> path;
	void addedge(int u, int v, int capa, int d) {
		edge *e1 = new edge(v, capa, d, 0);
		edge *e2 = new edge(u, 0, -d, 0);
		e1->rev = e2;
		e2->rev = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}
	bool SPFA() {
		vector<int> dis(MAX_V, MAX), inQ(MAX_V);
		P.assign(MAX_V, -1);
		path.assign(MAX_V, 0);
		queue<int> q;
		dis[S] = 0;
		inQ[S] = 1;
		q.push(S);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			inQ[u] = 0;
			for (edge *e : adj[u]) {
				int v = e->to;
				if (e->spare() > 0 && dis[v] > dis[u] + e->d) {
					dis[v] = dis[u] + e->d;
					P[v] = u;
					path[v] = e;
					if (!inQ[v]) {
						q.push(v);
						inQ[v] = 1;
					}
				}
			}
		}
		return P[T] != -1;
	}
	pii flow() {
		int work = 0, money = 0;
		while (SPFA()) {
			int f = MAX;
			for (int i = T; i != S; i = P[i]) {
				f = min(f, path[i]->spare());
			}
			for (int i = T; i != S; i = P[i]) {
				path[i]->addflow(f);
				money += f*path[i]->d;
			}
			work += f;
		}
		return { work, money };
	}
};
int n, m;
int ver[501], coin[501];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int tc; cin >> tc;
	while (tc--) {
		cin >> n >> m;
		S = 0;
		T = 501;
		MCMF mf = MCMF();
		for (int i = 1; i <= m; i++) {
			int x, y; cin >> x >> y;
			mf.addedge(x, y, 10000, 1);
			mf.addedge(y, x, 10000, 1);
		}
		for (int i = 1; i <= n; i++) {
			cin >> ver[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> coin[i];
		}
		for (int i = 1; i <= n; i++) {
			if (ver[i] != coin[i]) {
				if (coin[i] == 0) {
					mf.addedge(S, i, 1, 0);
				}
				else {
					mf.addedge(i, T, 1, 0);
				}
			}
		}
		cout << mf.flow().second<<'\n';
	}
}