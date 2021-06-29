/*
	[BOJ 14461] 소가 길을 건너간 이유 7
	Algorithm : Dijkstra
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)1e9;

int n, t;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int a[101][101];
int dis[101][101][4];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			for (int k = 0; k < 4; k++) dis[i][j][k] = MAX;
		}
	}
	dis[1][1][0] = 0;
	priority_queue<tuple<int, int, int, int>> pq;
	pq.push(make_tuple(0, 1, 1, 0));
	while (!pq.empty()) {
		auto [d, x, y, cnt] = pq.top(); pq.pop();
		if (-d > dis[x][y][cnt] || (x== n && y == n)) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
				if (cnt == 2) {
					if (dis[nx][ny][cnt+1] > -d + t + a[nx][ny]) {
						dis[nx][ny][cnt+1] = -d + t + a[nx][ny];
						pq.push(make_tuple(-dis[nx][ny][cnt+1], nx, ny, 3));
					}
				}
				else {
					if (dis[nx][ny][cnt%3 + 1] > -d + t) {
						dis[nx][ny][cnt%3 + 1] = -d + t;
						pq.push(make_tuple(-dis[nx][ny][cnt%3 + 1], nx, ny, cnt%3 + 1));
					}
				}
			}
		}
	}
	cout << min({ dis[n][n][1], dis[n][n][2], dis[n][n][3] });
}