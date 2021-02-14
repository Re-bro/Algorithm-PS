/* [BOJ 10868] ÃÖ¼Ú°ª
	Algorithm : Sparse table
*/
#include<bits/stdc++.h>
using namespace std;

int a[100001];
int dp[100001][20];
int lg[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i][0] = a[i];
	}
	for (int k = 1; (1 << k) <= n; k++) {
		for (int i = 1; i  + (1<<k) - 1<= n; i++) {
			dp[i][k] = min(dp[i][k - 1], dp[i + (1 << (k - 1))][k - 1]);
		}
	}
	lg[1] = 0;
	for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		int l = lg[b - a + 1];
		cout << min(dp[a][l], dp[b-(1<<l)+1][l])<<'\n';
	}
}
