/* [BOJ 20293] 연료가 부족해
	Algorithm : DP

	풀이 : https://wogud6792.tistory.com/78
*/


#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e9;
int A[3001][3001];
int dp[3001][3001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int R, C, N; cin >> R >> C>>N;
	for (int i = 1; i <= N; i++) {
		int a, b, c; cin >> a >> b >> c;
		A[a][b] = c;
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) dp[i][j] = MAX;
	}
	dp[R][C] = 0;
	for (int i = R; i >= 1; i--) {
		for (int j = C; j >= 1; j--) {
			if (i < R) dp[i][j] = min(max(dp[i + 1][j] + 1 - A[i][j], 0), dp[i][j]);
			if (j < C) dp[i][j] = min(max(dp[i][j + 1] + 1 - A[i][j], 0), dp[i][j]);
		}
	}
	cout << dp[1][1];
}