/*
	[BOJ 2315] °¡·Îµî ²ô±â
	Algorithm : DP
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
using pii = pair<int, int>;
const int MAX = (int)1e9;

int dp[1010][1010][2];
int psum[1010];
int n, m;
pii a[1010];
int sol(int l, int r, int pos) {
	if (l == 1 && r == n) return 0;
	int &ret = dp[l][r][pos];
	if (ret != -1) return ret;
	ret = MAX;
	int R = psum[n] - (psum[r] - psum[l - 1]);
	int now = (pos == 0 ? a[l].first : a[r].first);
	if (l > 1) ret = min(ret, sol(l - 1, r, 0) + R * (now - a[l - 1].first));
	if (r < n) ret = min(ret, sol(l, r + 1, 1) + R * (a[r + 1].first - now));
	
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	ini(dp, -1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
		psum[i] = psum[i - 1] + a[i].second;
	}
	cout << sol(m, m, 0);
}