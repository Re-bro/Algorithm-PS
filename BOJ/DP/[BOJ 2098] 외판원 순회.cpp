/* 
	[BOJ 2098] 외판원 순회
	Algorithm : DP / Bit DP
 */
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
const int MAX = (int)1e9;
int dp[17][1 << 16];
int w[17][17];
int n;
int sol(int now, int state) {
	if (state == (1 << n) - 1) {
		if (w[now][1] == 0) return MAX;
		return w[now][1];
	}
	int &ret = dp[now][state];
	if (ret != -1) return ret;
	ret = MAX;
	for (int i = 1; i <= n; i++) {
		if (((state & (1 << (i - 1))) == 0) && w[now][i] > 0) ret = min(ret, sol(i, state | (1 << (i - 1))) + w[now][i]);
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> w[i][j];
	}
	ini(dp, -1);
	cout<<sol(1, 1);
}