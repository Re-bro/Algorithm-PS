/* [BOJ 11062] 카드 게임
	Algorithm : DP

	dp[i][j][k]
	k = 0 : 근우 차례 / k = 1 : 명우 차례
	근우를 기준으로 보면, 명우 차례에는 명우가 최선의 전략으로 임하므로 
	둘 중 더 작은 값을 근우가 가져간다. 
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
int dp[1001][1001][2];
int a[1001];
int sol(int l, int r, int turn) {
	if (l == r) {
		if (turn == 0) return a[l];
		else return 0;
	}
	int &ret = dp[l][r][turn];
	if (ret != -1) return ret;
	ret = 0;
	if (turn == 0) {
		ret = max(sol(l + 1, r, 1) + a[l], sol(l, r - 1, 1) + a[r]);
	}
	else ret = min(sol(l + 1, r, 0), sol(l, r - 1, 0));
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		ini(dp, -1);
		cout << sol(1, n, 0)<<'\n';
	}
}