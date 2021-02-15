/* [BOJ 12008] 262144
	Algorithm : DP / Sparse Table

	dp[i][j] = i index부터 시작해서 j를 만들 수 있는 index
	dp[i][j] = dp[dp[i][j-1] + 1][j-1] (dp[i][j-1] & dp[dp[i][j-1]+1][j-1] is valid)
*/
#include<bits/stdc++.h>

using namespace std;

int dp[263000][60];
int a[263000];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int k = 1; k < 60; k++) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == k) {
				dp[i][k] = i;
				ans = max(ans, k);
			}
			if (dp[i][k - 1] != 0 && dp[dp[i][k - 1] + 1][k - 1] != 0) {
				dp[i][k] = dp[dp[i][k - 1] + 1][k - 1];
				ans = max(ans, k);
			}
		}
	}
	cout << ans;
}