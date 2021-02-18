/* [BOJ 10319] ���� ����Į����
	Algorithm : Maximum flow
	
	s�� �ִ� 100�̹Ƿ�, �� ������ �����ð���ŭ �������ش�. 
	�׷��� �� ������ �ִ� 100���� �������� ������ �ǰ�, a���� b�� p���� t�ð��� �ҿ��ؼ� �̵��Ѵٸ�, 
	a+k -> b+k+t �� �뷮�� p�� ������ �������ش�. 
	�׸��� �� ���������� ���� �����ð����� �̵��ϴ� ������ a + i -> a+i+1�� ������ش�.

	������ ī���� �ð����⵵�� min(O(VE^2), O(Ef))�̰�, f�� �ִ� 100�̹Ƿ� O(Ef) ���� ���డ���ϴ�.
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
#define MAX_V 102000
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
	void del() {
		for (int i = 0; i < MAX_V; i++) adj[i].clear();
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int tc; cin >> tc;
	Maxflow mf = Maxflow();
	while (tc--) {
		int n; cin >> n;
		int i, g, s; cin >> i >> g >> s;
		S = 0;
		T = 101999;
		int m; cin >> m;
		mf.addedge(S, i*(s + 1), g);
		for (int i = 1; i <= m; i++) {
			int a;  cin >> a;
			for (int j = 0; j <= s; j++) {
				mf.addedge(a*(s + 1) + j, T, 100);
			}
		}
		int r; cin >> r;
		for (int i = 1; i <= r; i++) {
			int a, b, p, t; cin >> a >> b >> p >> t;
			for (int j = 0; j <= s - t; j++) {
				mf.addedge(a*(s + 1) + j, b*(s + 1) + j + t, p);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= s; j++) {
				mf.addedge(i*(s + 1) + j - 1, i*(s + 1) + j, 100);
			}
		}
		cout << mf.flow() << '\n';
		mf.del();
	}
}