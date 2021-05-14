/*
	[BOJ 20220] Human Pyramid
	Algorithm : DP

	solution by https://commissies.ch.tudelft.nl/chipcie/archief/2020/dapc/solutions.pdf
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;

ll dp[101][5055][101];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int h, s; cin >> h >> s;
	dp[0][0][0] = 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 0; j <= min(s, i*(i + 1) / 2); j++) {
			for (int k = i; k >= 0 ; k--) {
				if (j - k < 0) continue;
				dp[i][j][k] = dp[i][j][k + 1] + (k != 0 ? dp[i - 1][j - k][k - 1] : dp[i-1][j-k][0]);
				dp[i][j][k] %= MOD;
			}
		}
	}
	cout << dp[h][s][0];
}