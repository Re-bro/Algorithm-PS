/*
	[BOJ 5573] ªÍ√•
	Algorithm : DP
*/

#include<bits/stdc++.h>
using namespace std;

int A[1010][1010];
int dp[1010][1010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int h, w, n; cin >> h >> w >> n;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> A[i][j];
		}
	}
	dp[1][1] = n - 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (i > 1) dp[i][j] += (A[i - 1][j] == 0 ? (dp[i - 1][j] + 1) / 2 : dp[i - 1][j] / 2);
			if (j > 1) dp[i][j] += (A[i][j - 1] == 1 ? (dp[i][j - 1] + 1) / 2 : dp[i][j - 1] / 2);
		}
	}
	int x = 1, y = 1;
	while (x <= h && y <= w) {
		if ((A[x][y] + dp[x][y]) % 2) y++;
		else x++;
	}
	cout << x << ' ' << y << '\n';
}