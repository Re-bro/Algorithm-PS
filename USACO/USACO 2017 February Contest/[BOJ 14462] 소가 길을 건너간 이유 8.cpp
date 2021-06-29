/*
	[BOJ 14462] 소가 길을 건너간 이유 8
	Algorithm : DP
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;

int dp[1010][1010];
int L[1010], R[1010];
int n;
int sol(int l, int r) {
	int& ret = dp[l][r];
	if (l == n + 1 || r == n + 1) return 0;
	if (ret != -1) return ret;
	ret = 0;
	if (abs(L[l] - R[r]) <= 4) ret = max(ret, sol(l + 1, r + 1) + 1);
	ret = max(ret, sol(l + 1, r));
	ret = max(ret, sol(l, r + 1));
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> L[i];
	for (int i = 1; i <= n; i++) cin >> R[i];
	ini(dp, -1);
	cout << sol(1, 1);
}