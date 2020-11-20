/* [BOJ 20183] 골목 대장 호석
	Algorithm : Dijkstra's algorithm / binary search

	1부터 1e9까지의 값 중 하나를 골라서 해당 값 이하인 간선들만 이용하여 다익스트라.
	값을 고르는 과정은 이분탐색 이용
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
ll dis[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	ll N, M, A, B, C; cin >> N >> M >> A >> B >> C;
	vector<vector<pll>>adj(N + 1, vector<pll>());
	for (int i = 1; i <= M; i++) {
		ll a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	int s = 1;
	int e = 1e9;
	int ans = MAX;
	while (s <= e) {
		int mid = (s + e) / 2;
		for (int i = 1; i <= N; i++) dis[i] = 1e18;
		priority_queue<pll> pq;
		pq.push({ 0, A });
		dis[A] = 0;
		while (!pq.empty()) {
			pll p = pq.top(); pq.pop();
			int u = p.second;
			for (pll v : adj[u]) {
				if (v.second > mid) continue;
				ll new_dis = -p.first + v.second;
				if (dis[v.first] > new_dis) {
					dis[v.first] = new_dis;
					if (v.first == B) continue;
					pq.push({ -new_dis, v.first});
				}
			}
		}
		if (dis[B] <= C) {
			e = mid - 1;
			ans = min(ans, mid);
		}
		else s = mid + 1;
	}
	if (ans == MAX) cout << -1;
	else cout << ans;
}
