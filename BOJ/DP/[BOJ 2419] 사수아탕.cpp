/*
	[BOJ 2419] »ç¼ö¾ÆÅÁ
	Algorithm : DP
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
const int MAX = (int)1e9;

int x[303];
int dp[303][303][2];
int n, m;
int sol(int l, int r, int pos, int cnt) {
	if (cnt == 0) return 0;
	int& ret = dp[l][r][pos];
	if (ret != -1) return ret;
	ret = MAX;
	int now;
	if (pos == 0) now = x[l];
	else now = x[r];
	if (l > 1) ret = min(ret, sol(l - 1, r, 0, cnt - 1) + cnt * (now - x[l - 1]));
	if (r < n+1) ret = min(ret, sol(l, r + 1, 1, cnt - 1) + cnt * (x[r + 1] - now));
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> x[i];
	sort(x + 1, x + n + 2);
	int s = lower_bound(x + 1, x + n + 2, 0) - x;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ini(dp, -1);
		ans = max(ans, i * m - sol(s, s, 0, i));
	}
	cout << ans;
}