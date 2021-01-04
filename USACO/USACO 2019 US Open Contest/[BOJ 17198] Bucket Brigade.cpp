/* [BOJ 17198] Bucket Brigade
	Algorithm : BFS
	
	바위를 거치지 않고 B에서 L까지 가는 최단 거리를 구하는 문제이다.
*/
#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
const int MAX = (int)2e9;
int dis[10][10];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	vector<string> v(10);
	int a, b;
	int c, d;
	for (int i = 0; i < 10; i++) {
		cin >> v[i];
		for (int j = 0; j < 10; j++) {
			dis[i][j] = MAX;
			if (v[i][j] == 'B') {
				a = i;
				b = j;
			}
			else if (v[i][j] == 'L') {
				c = i;
				d = j;
			}
		}
	}
	queue<pii>q;
	q.push({ a, b });
	dis[a][b] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10) {
				if (dis[nx][ny] > dis[x][y] + 1 && v[nx][ny] != 'R') {
					dis[nx][ny] = dis[x][y] + 1;
					if (v[nx][ny] != 'L') {
						q.push({ nx, ny });
					}
				}
			}
		}
	}
	cout << dis[c][d] - 1;
}