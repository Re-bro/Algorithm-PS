/* [CF 1473E] Minimum Path
	Algorithm : Dijkstra

	�ٽ����� ���̵���, ��θ� ���� �ڿ� ������ �� �ִ񰪰� �ּڰ��� �̾��ִ� ���� �ƴ϶�
	2�� ������ ������ 0�� ������ ������ �ϳ��� ���� ����̴�.
	�ᱹ �ִ��� ������ �������� �ʴ� ���̰�, �ּ��� ������ �� �� �������� ���̴� 
	�� ���� ���� 2�� �������ų� 0�� �������� ��� ������ �� ����Ѵٸ� �ִܰŸ��� �������� �ȴ�.
	���� dijkstra �迭�� dis[N][2][2]�� �����Ͽ�, ���ݱ��� 2�� ������ ������ 0�� ������ ������ ���� �����ϴ����� �Ǵ��Ѵ�.
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