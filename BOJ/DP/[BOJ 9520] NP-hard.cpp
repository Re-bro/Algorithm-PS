/*
	[BOJ 9520] NP-hard
	Algorithm : DP
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

int dp[1510][1510];
int cost[1510][1510];
int n;
int sol(int l, int r) {
	int next = max(l, r) + 1;
	if (next == n + 1) return 0;
	int& ret = dp[l][r];
	if (ret != -1) return ret;
	ret = MAX;
	ret = min(ret, sol(next, r) + cost[next][l]);
	ret = min(ret, sol(l, next) + cost[r][next]);
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> cost[i][j];
	}
	ini(dp, -1);
	cout << sol(1, 1);
}