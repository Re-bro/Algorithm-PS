/* [BOJ 15504] 프로그래밍 대결
	Algorithm : MCMF

	각 참가자에 대해서 정점을 두 개씩 만들어 놓고,  (a와 a')
	참가자 i에 대해서 A[i] < A[j]를 만족하는 모든 참가자 j'에 간선을 연결해준다.
	즉, 해당 참가자가 누군가와 붙어서 지는 경우를 만들어준다. 
	N-1번 게임을 하게 되면, 실력이 가장 높은 사람을 제외하곤 모두 1번씩 패배하기 때문이다.
	간선의 용량은 1이고 비용은 A[i] ^ A[j] - (H[i] + H[j]) 가 된다. 
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

#define MAX_V 610
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
ll A[301], H[301], L[301];
int n;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n;
	MCMF mf = MCMF();
	S = 0;
	T = 601;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> H[i];
	for (int i = 1; i <= n; i++) cin >> L[i];
	for (int i = 1; i <= n; i++) {
		bool mx = true;
		for (int j = 1; j <= n; j++) {
			if (A[i] < A[j]) {
				mx = false;
				mf.addedge(i, 300 + j, 1, -((A[i] ^ A[j]) - H[i] - H[j]));
			}
		}
		if (!mx) {
			mf.addedge(S, i, 1, 0);
			mf.addedge(300 + i, T, L[i] - 1, 0);
		}
		else {
			mf.addedge(300 + i, T, L[i], 0);
		}
	}
	cout << -mf.flow().second;
}
