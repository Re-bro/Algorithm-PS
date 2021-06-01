/*
	[BOJ 10803] 정사각형 만들기
	Algorithm : DP
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
const int MAX = (int)1e8;

int dp[10101][101];
int sol(int n, int m) {
	if (n == 0 || m == 0) return 0;
	if (n == 1 || m == 1) return max(n, m);
	if (n == m) return 1;
	int &ret = dp[n][m];
	if (ret != -1) return ret;
	ret = MAX;
	if (n / m >= 3) 	return ret = min(ret, sol(n - m, m) + 1);
	if (m / n >= 3) return ret = min(ret, sol(n, m - n) + 1);
	for (int i = 1; i < n; i++) {
		ret = min(ret, sol(i, m) + sol(n - i, m));
	}
	for (int i = 1; i < m; i++) {
		ret = min(ret, sol(n, i) + sol(n, m - i));
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	ini(dp, -1);
	cout << sol(n, m);
}