/*
	[Kickstart Round A 2021] Rabbit House
	Algorithm : Dijkstra
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int a[301][301];
int tmp[301][301];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int r, c; cin >> r >> c;
		ll ans = 0;
		priority_queue<pair<int, pii>> pq;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cin >> a[i][j];
				tmp[i][j] = a[i][j];
				pq.push({ a[i][j], {i, j} });
			}
		}
		while (!pq.empty()) {
			int cost = pq.top().first;
			auto [x, y] = pq.top().second;
			pq.pop();
			if (cost < tmp[x][y]) continue;
			tmp[x][y] = cost;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 1 && nx <= r && ny >= 1 && ny <= c) {
					if (tmp[nx][ny] < cost - 1) {
						tmp[nx][ny] = cost - 1;
						pq.push({ cost - 1, {nx, ny} });
					}
				}
			}
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				ans += tmp[i][j] - a[i][j];
			}
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}
}