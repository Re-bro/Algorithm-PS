/*
	[BOJ 5626] Á¦´Ü
	Algorithm : DP / Sliding window
*/

#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;

int h[10101];
ll dp[2][5010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	if (h[1] <= 0) dp[1][0] = 1;
	for (int i = 2; i <= n; i++) {
		int x = i % 2;
		int y = (i + 1) % 2;
		for (int j = 0; j <= 5000; j++) {
			dp[x][j] = 0;
		}
		if (h[i] == -1) {
			for (int j = 0; j <= 5000; j++) {
				dp[x][j] += (j > 0 ? dp[y][j - 1] : 0)+ dp[y][j] + dp[y][j + 1];
				dp[x][j] %= MOD;
			}
		}
		else if (h[i] > 5000) continue;
		else {
			dp[x][h[i]] += (h[i] > 0 ? dp[y][h[i]- 1] : 0) + dp[y][h[i]] + dp[y][h[i] + 1];
			dp[x][h[i]] %= MOD;
		}
	}
	cout << dp[n%2][0] % MOD;
}