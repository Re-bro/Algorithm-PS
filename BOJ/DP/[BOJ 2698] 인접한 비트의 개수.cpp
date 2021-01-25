/* [BOJ 2698] 인접한 비트의 개수
	Algorithm : DP

	dp[i][j][k] := j개의 인접한 비트 개수를 갖고, 이전 숫자가 k인 [i ~ n] 수열의 개수
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
int n, k;
int dp[101][101][2];
int sol(int idx, int cnt, int pre) {
	if (idx == n + 1) return (cnt ? 0 : 1);
	int &ret = dp[idx][cnt][pre];
	if (ret != -1) return ret;
	ret = sol(idx + 1, (pre ? cnt - 1 : cnt), 1) + sol(idx+1, cnt, 0);
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		ini(dp, -1);
		cin >> n >> k;
		cout << sol(1, k, 0) << '\n';
	}
}