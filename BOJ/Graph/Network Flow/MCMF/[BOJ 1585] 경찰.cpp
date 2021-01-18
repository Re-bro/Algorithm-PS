/* [BOJ 1585] 경찰
	Algorithm : MCMF

	들어가는 시간을 in이라고 하고, 나오는 시간을 out이라고 하면
	in < out을 만족하는 정보들끼리 간선을 연결해준다. 
	이때, in < out이고, out - in < t이면 과속이므로 간선의 정보를 다르게 추가한다.
	최댓값은 간선의 비용 부호를 모두 바꿔서 구해준다. 
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
#define MAX_V 110
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
int n; 
int in[51], out[51];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n;
	MCMF mf = MCMF();
	MCMF mf2 = MCMF();
	S = 0; T = 101;
	for (int i = 1; i <= n; i++) {
		cin >> in[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> out[i];
	}
	int t, f; cin >> t >> f;
	for (int i = 1; i <= n; i++) {
		mf.addedge(0, i, 1, 0);
		mf.addedge(50 + i, 101, 1, 0);
		mf2.addedge(0, i, 1, 0);
		mf2.addedge(50 + i, 101, 1, 0);
		for (int j = 1; j <= n; j++) {
			if (in[i] < out[j] && out[j] - in[i] < t) {
				int k = out[j] - in[i] - t;
				mf.addedge(i, 50 + j, 1, min(f, k*k));
				mf2.addedge(i, 50 + j, 1, max(-f, -(k*k)));
			}
			else if(out[j] > in[i]){
				mf.addedge(i, 50 + j, 1, 0);
				mf2.addedge(i, 50 + j, 1, 0);
			}
		}
	}
	pii p1 = mf.flow();
	if (p1.first != n) return cout << -1, 0;
	cout << p1.second << ' ' << -mf2.flow().second;
}