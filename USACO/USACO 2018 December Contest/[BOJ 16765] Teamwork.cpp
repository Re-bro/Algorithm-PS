/*
	[BOJ 16765] Teamwork
	Algorithm : DP
*/
#include<bits/stdc++.h>

#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
int dp[10001], a[10001];
int n, k;
int sol(int idx) {
	if (idx == n + 1) return 0;
	int& ret = dp[idx];
	if (ret != -1) return ret;
	ret = 0;
	int mx = 0;
	for (int i = idx; i < idx + k && i <= n; i++) {
		mx = max(mx, a[i]);
		ret = max(ret, mx * (i - idx + 1) + sol(i + 1));
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ini(dp, -1);
	cout<<sol(1);
}