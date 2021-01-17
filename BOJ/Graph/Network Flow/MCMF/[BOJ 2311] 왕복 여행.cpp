/* [BOJ 2311] 왕복 여행
	Algorithm : MCMF

	무향 간선인 경우에 연결리스트로 구현한 mcmf에서는 
	굳이 역방향 간선의 capacity도 설정해줄 필요 없이 그냥 방향 간선을 두개 만들자....
	실수할 가능성이 매우 크다
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

#define MAX_V 1010
int S, T;
struct MCMF {
	struct edge {
		int to, c, f, d;
		edge* rev;
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
		edge* e1 = new edge(v, capa, d, 0);
		edge* e2 = new edge(u, 0, -d, 0);
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
			for (edge* e : adj[u]) {
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
				money += f * path[i]->d;
				path[i]->addflow(f);
			}
			work += f;
		}
		return { work, money };
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M; cin >> N >> M;
	MCMF mf = MCMF();
	for (int i = 1; i <= M; i++) {
		int a, b, c; cin >> a >> b >> c;
		mf.addedge(a, b, 1, c);
		mf.addedge(b, a, 1, c);
	}
	mf.addedge(0, 1, 2, 0);
	mf.addedge(N, N + 1, 2, 0);
	S = 0;
	T = N+1;
	int ans = 0;
	ans += mf.flow().second;
	cout << ans;
}