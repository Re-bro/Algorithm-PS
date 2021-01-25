/* [BOJ 1757] 달려달려
	Algorithm : DP

	dp[i][j] = i번째 위치에서 j의 지침지수를 가질 때 최대한 멀리 갈 수 있는 거리
	i에서 달리는 경우 dp[i][j] = max(dp[i][j], dp[i+1][j+1] + d[i])
	i에서 쉬는 경우 dp[i][j] = max(dp[i][j], dp[i+j][0])
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
const int MAX = (int)2e9;

int dp[10001][501];
int d[10001];
int n, m;

int sol(int pos, int k) {
	if (pos == n) return k == 0 ? 0 : -MAX;
	int &ret = dp[pos][k];
	if (ret != -1) return ret;
	ret = -MAX;
	if (k < m) ret = max(ret, sol(pos + 1, k + 1) + d[pos + 1]);
	if (k == 0) ret = max(ret, sol(pos + 1, k));
	if (k > 0 && pos+k <=n) ret = max(ret, sol(pos + k, 0));
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	ini(dp, -1);
	for (int i = 1; i <= n; i++) cin >> d[i];
	cout << sol(0, 0);
}