/* 
	[BOJ 6086] �ִ� ����
	Algorithm : Maximum flow
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;

#define MAX_V 100
int n;
int S, T;
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
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n;
	S = 0;
	T = 25;
	Maxflow mf = Maxflow();
	for (int i = 1; i <= n; i++) {
		char a, b; int c; cin >> a >> b >> c;
		a -= 'A';
		b -= 'A';
		mf.addedge(a, b, c, false);
	}
	cout << mf.flow();
}