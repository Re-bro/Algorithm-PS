/* [BOJ 2176] �ո����� �̵����
	Algorithm : Dijkstra / Tree DP

	S���� T�� �� ��, T�� ��������� �̵��Ѵٴ� �ǹ̴�, 
	x�� ���İ��ٸ� dist(S, T) > dist(x, T)�� �ǹ��Ѵ�.
	���� T���� �� ���������� �Ÿ��� ���ͽ�Ʈ��� ���� ��, 
	�Ÿ��� �� ª������ ��쿡�� dfs�� Ÿ�� �̵��Ѵ�. 
	�̵������ ������ dp�� ���Ѵ�.
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using pii = pair<int, int>;
vector<pii>adj[1001];
int dp[1001];
int dis[1001];
void dijk(int s) {
	dis[s] = 0;
	priority_queue<pii> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int cost = -pq.top().first; 
		int u = pq.top().second;
		pq.pop();
		if (dis[u] < cost) continue;
		for (pii v : adj[u]) {
			if (dis[v.first] > cost + v.second) {
				dis[v.first] = cost + v.second;
				pq.push({ -dis[v.first], v.first });
			}
		}
	}
}
int sol(int u) {
	if (u == 2 ) return dp[u] = 1;
	int &ret = dp[u];
	if (ret != -1) return ret;
	ret = 0;
	for (pii v : adj[u]) {
		if (dis[v.first] < dis[u]) {
			ret += sol(v.first);
		}
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M; cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	ini(dp, -1);
	fill(dis, dis + N + 1, (int)2e9);
	dijk(2);
	cout << sol(1);
}