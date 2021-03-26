/*
	[BOJ 17025] Icy Perimeter
	Algorithm : BFS
*/
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int A[1010][1010];
bool visited[1010][1010];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '#') A[i + 1][j + 1] = 1;
		}
	}
	int area = 0;
	int peri = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] || A[i][j] == 0) continue;
			queue<pii>q;
			q.push({ i, j });
			visited[i][j] = true;
			int cnt1 = 1;
			int cnt2 = 0;
			while (!q.empty()) {
				auto [x, y] = q.front(); q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (A[nx][ny] == 0) cnt2++;
					if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !visited[nx][ny] && A[nx][ny] == 1) {
						q.push({ nx, ny });
						cnt1++;
						visited[nx][ny] = true;
					}
				}
			}
			if (area < cnt1 || (area == cnt1 && cnt2 < peri)) {
				area = cnt1;
				peri = cnt2;
			}
		}
	}
	cout << area << ' ' << peri;
}