/* [BOJ 11410] 칙칙폭폭
	Algorithm : MCMF

	주어지는 정보인 도시 i에서 도시 j로의 사람 수와 요금을 간선으로 연결해준다.
	그리고, 꼭 다음 도시로 갈 때 기차에 사람이 꽉찰 필요는 없으므로, 
	i에서 j로 용량이 무한이고, 비용이 0인 간선을 추가해서 나머지 사람들은 뒤에서 탈 수도 있도록 해준다. 
	기차에 최대 P명이 탈 수 있는 것은 각 도시를 두개의 정점으로 나누고 그 두 정점을
	용량이 P인 간선으로 연결해서 도시를 최대 P명만 지날 수 있도록 해준다. 
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

#define MAX_V 101
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

int num[51][51], cost[51][51];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n, p; cin >> n >> p;
	MCMF mf = MCMF();
	for (int i = 1; i < n; i++) {
		for (int j = i+1; j <= n; j++) {
			cin >> num[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = i+1; j <= n; j++) {
			cin >> cost[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		mf.addedge(2 * i - 1, 2 * i, p, 0);
	}
	for (int i = 1; i < n; i++) {
		for (int j = i+1; j <= n; j++) {
			mf.addedge(2 * i, 2 * j - 1, num[i][j], -cost[i][j]);
			mf.addedge(2 * i, 2 * j - 1, 1000, 0);
		}
	}
	S = 1;
	T = 2 * n;
	cout << -mf.flow().second;
}