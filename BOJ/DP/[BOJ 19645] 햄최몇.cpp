/* [BOJ 19645] 햄최몇?
	Algorithm : DP

	dp[i][j][k] : j = 두번째로 많은 사람 / k = 세번째로 많은 사람 / i = 현재 보고 있는 햄버거 
	total - j - k = 제일 많은 사람으로 정해지므로, j와 k만 고려해도 된다. 
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
int dp[52][1251][850];
int a[51];
int n, total, ans;
int sol(int idx, int x, int y, int z) {
	int r = total - x - y - z;
	if (r + x < y || r + z < x || r + y < ans) return 0;
	int& ret = dp[idx][x][y];
	if (ret != -1) return ret;
	if (idx == n + 1) {
		if (x >= y && z >= x) {
			ans = max(ans, y);
			return ret = 1;
		}
		else return ret = 0;
	}
	ret = 0;
	if(x + a[idx] <= total/2) ret |= sol(idx + 1, x + a[idx], y, z);
	if(y + a[idx] <= total/3) ret |= sol(idx + 1, x, y + a[idx], z);
	ret |= sol(idx + 1, x, y, z+a[idx]);
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		total += a[i];
	}
	ini(dp, -1);
	sol(1, 0, 0, 0);
	cout << ans;
}