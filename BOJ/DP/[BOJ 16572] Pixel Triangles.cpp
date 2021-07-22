/*
	[BOJ 16572] Pixel Triangles
	Algorithm : DP
*/
#include<bits/stdc++.h>
using namespace std;

int a[2020][2020];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int x, y, z;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> z;
		if (z > a[x][y]) a[x][y] = z;
	}
	int cnt = 0;
	for (int i = 1; i <= 2000; i++) {
		for (int j = 1; j <= 2000; j++) {
			if (a[i][j] > 0) {
				a[i + 1][j] = max(a[i + 1][j], a[i][j] - 1);
				a[i][j + 1] = max(a[i][j + 1], a[i][j] - 1);
				cnt++;
			}
		}
	}
	cout << cnt;
}