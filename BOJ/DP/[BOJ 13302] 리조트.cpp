/* [BOJ 13302] 리조트
	Algorithm : DP

	dp[i][j] := i일에 j개의 쿠폰을 가지고 있을 때, n일까지 필요한 최소 비용
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
const int MAX = (int)2e9;
int n, m;
bool no[110];
int dp[110][110];
int sol(int day, int coupon) {
	if (day >= n + 1) return 0;
	int &ret = dp[day][coupon];
	if (ret != -1) return ret;
	ret = MAX;
	if (coupon >= 3) {
		for (int i = day + 1; i <= n + 5; i++) {
			if (!no[i]) {
				ret = min(ret, sol(i, coupon - 3));
				break;
			}
		}
	}
	for (int i = day + 1; i <= n + 5; i++) {
		if (!no[i]) {
			ret = min(ret, sol(i, coupon) + 10000);
			break;
		}
	}
	for (int i = day + 3; i <= n + 5; i++) {
		if (!no[i]) {
			ret = min(ret, sol(i, coupon + 1) + 25000);
			break;
		}
	}
	for (int i = day + 5; i <= n + 5; i++) {
		if (!no[i]) {
			ret = min(ret, sol(i, coupon + 2) + 37000);
			break;
		}
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	ini(dp, -1);
	for (int i = 1; i <= m; i++) {
		int a; cin >> a;
		no[a] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (!no[i]) {
			cout << sol(i, 0);
			return 0;
		}
	}
	cout << 0;
}