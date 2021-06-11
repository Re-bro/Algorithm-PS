/*
	[BOJ 1311] 할 일 정하기 1
	Algorithm : Bit DP / DP
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
const int MAX = (int)2e9;

int d[21][21];
int dp[21][1 << 20];
int n;
int sol(int k, int bit) {
	if (k == n+1) return 0;
	int& ret = dp[k][bit];
	if (ret != -1) return ret;
	ret = MAX;
	for (int i = 0; i < n; i++) {
		if (((1 << i) & bit) == 0) {
			ret = min(ret, sol(k + 1, bit | (1 << i)) + d[i + 1][k]);
		}
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> d[i][j];
	}
	ini(dp, -1);
	cout<<sol(1, 0);
}