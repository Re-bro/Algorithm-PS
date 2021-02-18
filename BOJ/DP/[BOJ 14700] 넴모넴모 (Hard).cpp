/* 
	[BOJ 14700] 넴모넴모 (Hard)
	Algorithm : Bit DP
	현재 위치를 (x, y)라고 하고, n = min(n, m)이라고 하면 
	(x-1, y-1) ~ (x-1, n) , (x, 1) ~ (x, y-1) 총 n+1개의 칸의 정보만 계속해서 담고 있으면 된다.
*/
#include<bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
int total, n, m;
int dp[301][1 << 18];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//   freopen("input.txt", "r", stdin);
	cin >> n >> m;
	total = n * m;
	n = min(n, m);
	dp[0][0] = 1;
	for (int i = 0; i < total; i++) {
		for (int j = 0; j < (1 << (n + 1)); j++) {
			if (i%n == 0 || (j & 3) != 3 || (j & (1 << n)) == 0) {
				dp[i + 1][(j >> 1) | (1 << n)] += dp[i][j];
				dp[i + 1][(j >> 1) | (1 << n)] %= MOD;
			}
			dp[i + 1][j >> 1] += dp[i][j];
			dp[i + 1][j >> 1] %= MOD;
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << (n + 1)); i++) {
		ans = (ans + dp[total][i]) % MOD;
	}
	cout << ans;
}