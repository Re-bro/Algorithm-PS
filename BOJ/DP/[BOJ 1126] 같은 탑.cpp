/*
	[BOJ 1126] 같은 탑
	Algorithm : DP

	dp[i][j] = i번째 탑까지 사용하거나 버렸을 때, 두 탑의 차이가 j인 경우 더 높은 탑의 최대 높이
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
#define fi first
#define se second

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);

int dp[51][250505];
int n, a[51];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ini(dp, -1);
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		int k = a[i + 1];
		for (int j = 0; j <= 250000; j++) {
			if (dp[i][j] == -1) continue;
			if(j +k <= 250000) dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + k);
			if (k <= j) dp[i + 1][j - k] = max(dp[i + 1][j - k], dp[i][j]);
			else if(k - j <=250000) dp[i + 1][k - j] = max(dp[i + 1][k - j], dp[i][j] + k - j);
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
		}
	}
	if (dp[n][0] <= 0) cout << -1;
	else 	cout << dp[n][0];
}