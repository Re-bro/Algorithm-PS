/* 
	[BOJ 1420] 학교 가지마!	
	Algorithm : Maximum flow / Min cut Max flow

	한 정점을 지나는 많은 경우들은 벽 하나로 모두 제거해줄 수 있으므로, 
	각 정점을 한번만 지나도록 정점 분할을 해준다.
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

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
#define MAX_V 20010
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
int n, m; 
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	Maxflow mf = Maxflow();
	cin >> n >> m;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '#') continue;
			else if (v[i][j] == 'K') {
				S = (i*m + j) * 2;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] == 'H') {
						return cout << -1, 0;
					}
				}
			}
			else if (v[i][j] == 'H') {
				T = (i*m + j) * 2+1;
			}
			int now = i * m + j;
			if(v[i][j] == '.') mf.addedge(now * 2 , now * 2+1, 1);
			else if (v[i][j] != '#') mf.addedge(now * 2 , now * 2+1, MAX);
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#') {
					mf.addedge(now * 2+1, (nx*m + ny)*2, 1);
				}
			}
		}
	}
	cout << mf.flow();
}