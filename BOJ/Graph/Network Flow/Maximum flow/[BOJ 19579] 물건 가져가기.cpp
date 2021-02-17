/* [BOJ 19579] 물건 가져가기
	Algorithm : Maximum flow / Min cut Max flow

	풀이 : https://upload.acmicpc.net/789ee426-cf86-40fa-aa64-733c50e96539/
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
#define MAX_V 210
int S, T;
vector<int> ans;
bool visited[210];
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
	void trace(int u, int p) {
		for (auto e : adj[u]) {
			if (e->to == p || visited[e->to]) continue;
			if (e->c >= 0) {
				if(e->f == e->c) continue;
				else {
					ans.push_back(e->to);
					visited[e->to] = true;
					trace(e->to, u);
				}
			}
		}
	}
};
int t[201];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n, m; cin >> n >> m;
	S = 0; T = n + 1;
	Maxflow mf = Maxflow();
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		if (t[i] >= 0) mf.addedge(S, i, t[i]);
		else mf.addedge(i, T, -t[i]);
	}
	for (int i = 1; i <= m; i++) {
		int s, e; cin >> s >> e;
		mf.addedge(s, e, MAX);
	}
	mf.flow();
	mf.trace(S, S);
	cout << ans.size() << '\n';
	for (int i : ans) cout << i << ' ';
}