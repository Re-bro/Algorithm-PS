/*
	[Template] Divide and Conquer Optimization

	DP[t][i] = min(DP[t-1][j] + C[j][i])  (1<= j <n) 
	Condition : C[a][c] + C[b][d] <= C[a][d] + C[b][c]  for all a <= b <= c <= d

	Naive Time Complexity : O(KN^2)
	DnC Opt Time Complexity : O(KNlogN)
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;

int dp[1000][1000];
int C[1000][1000];
int n, m;
void dnc(int t, int s, int e, int l, int r) {
	if (s > e) return;
	int m = (s + e) / 2;
	int opt = l;
	for (int i = l; i <= r; i++) {
		if (dp[t - 1][opt] + C[opt][m] > dp[t - 1][i] + C[i][m]) opt = i;
	}
	dp[t][m] = dp[t - 1][opt] + C[opt][m];
	dnc(t, s, m - 1, l, opt);
	dnc(t, m + 1, e, opt, r);
}
int main(void) {
	for (int i = 1; i <= n; i++) dnc(i, 1, m, 0, m);
}