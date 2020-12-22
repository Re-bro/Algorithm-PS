/* [BOJ 15906] 변신 이동 게임
	Algorithm : Dijkstra

	현재 상태가 일반 모드라면, 상하좌우로 1칸 움직이거나 변신모드로 변환 후 워프로 이동 가능하다.
	현재 상태가 변신 모드라면, 상하좌우로 1칸 또는 워프로 이동 가능하다. (일반모드로 변환하는 것은 비용 x)
	따라서 각 지점들로 연결하는 간선을 생각해서 다익스트라를 이용해준다.
	dp[x][y][0] = 현재 상태가 (0 : 일반모드, 1 : 워프모드) 일 때, 현재 위치까지 오는 최소 횟수
*/
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MAX = (int)2e9;

int N, t, r, c;
int dis[501][501][2];
vector<string> v(501);
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
void dijkstra(void) {
	priority_queue<pair<pii, pii>> q;
	dis[0][0][0] = 0;
	dis[0][0][1] = t;
	q.push({ {0, 0}, { 0, 0 }});
	q.push({ {-t, 1}, {0, 0} });
	while (!q.empty()) {
		int x = q.top().second.first;
		int y = q.top().second.second;
		int state = q.top().first.second;
		int val = -q.top().first.first;
		q.pop();
		if (dis[x][y][state] < val) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (dis[nx][ny][0] > dis[x][y][state] + 1) {
					dis[nx][ny][0] = dis[x][y][state] + 1;
					q.push({ {-dis[nx][ny][0], 0} ,{nx, ny} });
				}
			}
		}
		bool chk = false;
		vector<pii> tmp;
		for (int i = x - 1; i >= 0; i--) {
			if (v[i][y] == '#') { tmp.push_back({ i, y }); break; }
		}
		for (int i = x + 1; i < N; i++) {
			if (v[i][y] == '#') { tmp.push_back({ i, y }); break; }
		}
		for (int i = y - 1; i >= 0; i--) {
			if (v[x][i] == '#') { tmp.push_back({ x, i }); break; }
		}
		for (int i = y + 1; i < N; i++) {
			if (v[x][i] == '#') { tmp.push_back({ x, i }); break; }
		}
		for (pii p : tmp) {
			int nx = p.first;
			int ny = p.second;
			if (state == 0) {
				if (dis[nx][ny][1] > dis[x][y][state] + t + 1) {
					dis[nx][ny][1] = dis[x][y][state] + t + 1;
					q.push({ { -dis[nx][ny][1], 1 },{ nx, ny } });
				}
			}
			else {
				if (dis[nx][ny][1] > dis[x][y][state] + 1) {
					dis[nx][ny][1] = dis[x][y][state] + 1;
					q.push({ { -dis[nx][ny][1], 1 },{ nx , ny } });
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> t;
	cin >> r >> c;
	r--; c--;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		for (int j = 0; j < N; j++) {
			dis[i][j][0] = dis[i][j][1] = MAX;
		}
	}
	dijkstra();
	cout << min(dis[r][c][0], dis[r][c][1]);
}