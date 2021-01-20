/* [CF 1473E] Minimum Path
	Algorithm : Dijkstra

	핵심적인 아이디어는, 경로를 구한 뒤에 간선들 중 최댓값과 최솟값을 뽑아주는 것이 아니라
	2번 더해질 간선과 0번 더해질 간선을 하나씩 고르는 방식이다.
	결국 최대인 간선은 더해지지 않는 셈이고, 최소인 간선은 두 번 더해지는 셈이니 
	각 간선 별로 2번 더해지거나 0번 더해지는 모든 경우들을 다 고려한다면 최단거리가 구해지게 된다.
	따라서 dijkstra 배열을 dis[N][2][2]로 선언하여, 지금까지 2번 더해진 간선과 0번 더해진 간선이 각각 존재하는지를 판단한다.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

vector<pll>adj[200001];
ll dis[200001][2][2];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		ll u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
	for (int i = 1; i <= n; i++) {
		dis[i][0][0] = dis[i][0][1] = dis[i][1][0] = dis[i][1][1] = 1e18;
	}
	dis[1][0][0] = 0;
	priority_queue<tuple<ll, ll, int, int >> pq;
	pq.push(make_tuple(0LL, 1LL, 0, 0));
	while (!pq.empty()) {
		auto[cost, u, a, b] = pq.top();
		pq.pop();
		cost = -cost;
		if (cost > dis[u][a][b]) continue;
		for (auto[v, w] : adj[u]) {
			ll new_dis = cost + w;
			if (dis[v][a][b] > new_dis) {
				dis[v][a][b] = new_dis;
				pq.push(make_tuple(-dis[v][a][b], v, a, b));
			}
			if (a == 0 && b == 0 && dis[v][1][1] > new_dis) {
				dis[v][1][1] = new_dis;
				pq.push(make_tuple(-dis[v][1][1], v, 1, 1));
			}
			if (a == 0 && dis[v][1][b] > new_dis + w) {
				dis[v][1][b] = new_dis + w;
				pq.push(make_tuple(-dis[v][1][b], v, 1, b));
			}
			if (b == 0 && dis[v][a][1] > new_dis - w) {
				dis[v][a][1] = new_dis - w;
				pq.push(make_tuple(-dis[v][a][1], v, a, 1));
			}
		}
	}
	for (int i = 2; i <= n; i++) cout << dis[i][1][1] << ' ';
}