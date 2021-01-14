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

#define MAX_V 2502
int S, T;
int table[6][6] = { { 10, 8, 7, 5, 0, 1 },{ 8, 6, 4, 3,0, 1 },{ 7, 4, 3, 2, 0, 1 },
{ 5, 3, 2, 2, 0, 1 },{ 0, 0, 0, 0, 0, 0 },{ 1, 1, 1, 1,0, 0 } };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
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

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N, M; cin >> N >> M;
	MCMF mf = MCMF();
	vector<string> A(N);
	S = 2500;
	T = 2501;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int u = i*M + j;
			mf.addedge(u, T, 1, 0);
			if ((i + j) % 2) {
				mf.addedge(S, u, 1, 0);
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
						mf.addedge(u, nx*M + ny, 1, -table[A[i][j] - 'A'][A[nx][ny] - 'A']);
					}
				}
			}
		}
	}
	pii ans = mf.flow();
	cout << -ans.second;
}