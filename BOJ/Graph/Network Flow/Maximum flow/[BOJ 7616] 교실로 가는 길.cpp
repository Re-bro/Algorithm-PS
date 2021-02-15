/* [BOJ 7616] 교실로 가는 길	
	Algorithm : Maximum flow

	유량이 이미 흐르고 있는 간선의 역간선, 즉 flow < 0인 간선으로 역추적하여 경로를 구한다.
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;
const int MAX = (int)2e9;
#define MAX_V 10010
int S, T;
int cnt;
int k, n;
struct Maxflow {
	struct edge {
		int to, c, f;
		edge *rev;
		edge(int v, int c) : to(v), c(c), f(0) {}
		int spare() { return c - f; }
		void add_flow(int flow) {
			f += flow;
			rev->f -= flow;
		}
	};
	vector<edge*> adj[MAX_V];
	vector<int> P;
	vector<edge*> path;
	void addedge(int u, int v, int c, bool directed = true) {
		edge *e1 = new edge(v, c);
		edge *e2 = new edge(u, directed ? 0 : c);
		e1->rev = e2;
		e2->rev = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}
	int flow() {
		int res = 0;
		while (1) {
			vector<int> P(MAX_V, -1);
			vector<edge*>back(MAX_V);
			queue<int> q;
			P[S] = S;
			q.push(S);
			while (!q.empty() && P[T] == -1) {
				int now = q.front(); q.pop();
				for (auto e : adj[now]) {
					int next = e->to;
					if (P[next] == -1 && e->spare() > 0) {
						P[next] = now;
						back[next] = e;
						q.push(next);
					}
				}
			}
			if (P[T] == -1) break;
			int val = MAX;
			for (int i = T; i != S; i = P[i]) {
				val = min(val, back[i]->spare());
			}
			for (int i = T; i != S; i = P[i]) {
				back[i]->add_flow(val);
			}
			res += val;
		}
		return res;
	}
	vector<int> res;
	void trace(int u) {
		if (cnt >= k) return;
		if(u%2) res.push_back(u/2 + 1);
		if (u == S) {
			cnt++;
			for (int i = sz(res) - 1; i >= 0; i--) cout << res[i] << ' ';
			cout << '\n';
			res.pop_back();
			return;
		}
		for (auto e : adj[u]) {
			int next = e->to;
			if (e->f < 0) {
				trace(next);
				e->f++;
			}
		}
		if(u%2) res.pop_back();
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	for(int tc = 1; ; tc++){
		 cin >> k >> n;
		cin.get();
		if (k == 0 && n == 0) break;
		cout << "Case " << tc << ':' << '\n';
		S = 1; T = 4;
		Maxflow mf = Maxflow();
		for (int i = 1; i <= n; i++) {
			mf.addedge(i * 2 - 1, i * 2, (i <=2 ? 10000 : 1));
			string s; getline(cin, s);
			int tmp = 0;
			for (int j = 0; j < sz(s); j++) {
				if (s[j] == ' ') {
					mf.addedge(i * 2, tmp * 2 - 1, 1);
					tmp = 0;
				}
				else tmp = tmp * 10 + s[j] - '0';
			}
			mf.addedge(i * 2, tmp * 2 - 1, 1);
		}
		int res = mf.flow();
		if (res < k) cout << "Impossible\n";
		else {
			cnt = 0;
			mf.trace(T);
		}
		cout << '\n';
	}
}