/* [BOJ 14942] 개미
	Algorithm : BFS / Tree / Sparse Matrix

	주어지는 그래프는 트리이다. 
	1번방으로부터 각 방까지의 거리를 저장해두고, 각 방에서 1번방까지 올라가는데,
	단순히 부모만 타고 올라간다면 시간이 오래 걸린다.
	따라서 LCA처럼 희소 배열을 만들어서 현재 남은 에너지로 갈 수 있는 최대한 먼 2^k번째 조상으로 올라간다.
	그러면 logn만에 루트에 가장 가까운 방으로 올라갈 수 있다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);

int A[100001];
int P[100001][17];

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	vector<vector<pii>> adj(n + 1, vector<pii>());
	for (int i = 1; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	queue<int> q;
	q.push(1);
	vector<int> dis(n + 1, MAX);
	dis[1] = 0;
	dis[0] = -1e9;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (pii v : adj[u]) {
			if (dis[v.first] != MAX) continue;
			dis[v.first] = dis[u] + v.second;
			q.push(v.first);
			P[v.first][0] = u;
		}
	}
	for (int j = 1; j < 17; j++) {
		for (int i = 1; i <= n; i++) {
			P[i][j] = P[P[i][j - 1]][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		int now = A[i];
		int room = i;
		for (int j = 16; j >= 0; j--) {
			if (dis[room] - dis[P[room][j]] <= now) {
				now -= dis[room] - dis[P[room][j]];
				room = P[room][j];
			}
		}
		cout << max(room, 1) << '\n';
	}
}