/* 
	[BOJ 13261] 탈옥
	Algorithm : DP / DnC Opt

	dp[i][j] : i명의 간수가 j번째 칸까지 감시하는 최소 비용 
	dp[i][j] = min(dp[i-1][k] + (j-k)*(C[k+1] + C[k+2] + ... + C[j]))  (k < j)

	C[a][b] = a ~ b 칸을 감시하는 비용이라고 하면
	C는 monge array를 만족한다.
*/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll C[8001];
ll dp[801][8001];
void dnc(int t, int s, int e, int l, int r) {
	if (s > e) return;
	int m = (s + e) / 2;
	int opt = l;
	for (int i = l; i <= r && i<=m; i++) {
		if (dp[t - 1][opt] + (m - opt)*(C[m] - C[opt]) > dp[t - 1][i] + (m - i)*(C[m] - C[i])) opt = i;
	}
	dp[t][m] = dp[t - 1][opt] + (m - opt)*(C[m] - C[opt]);
	dnc(t, s, m - 1, l, opt);
	dnc(t, m + 1, e, opt, r);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int l, g; cin >> l >> g;
	for (int i = 1; i <= l; i++) {
		cin >> C[i];
		C[i] += C[i - 1];
	}
	for (int i = 1; i <= l; i++) {
		dp[1][i] = i * C[i];
	}
	for (int i = 2; i <= g; i++) dnc(i, 1, l, 0, l);
	cout << dp[g][l];
}