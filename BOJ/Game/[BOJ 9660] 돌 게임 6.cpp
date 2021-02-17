/* 
	[BOJ 9660] µπ ∞‘¿” 6
	Algorithm : Game Theory
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int dp[30];
int state[16];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	dp[0] = 0;
	dp[1] = dp[3] = dp[4] = 1;
	int len, start;
	for (int i = 5; ; i++) {
		dp[i] = ((dp[i - 1] & dp[i - 3] & dp[i - 4]) + 1) % 2;
		int k = 0;
		for (int j = 0; j < 4; j++) {
			k += dp[i - j] * (1 << j);
		}
		if (state[k] != 0) {
			start = state[k] - 3;
			len = i - state[k];
			break;
		}
		else state[k] = i;
	}
	ll n; cin >> n;
	if (n <= start + len + 3) {
		cout << (dp[n] ? "SK" : "CY");
	}
	else {
		n = (n - start) % len + start;
		cout << (dp[n] ? "SK" : "CY");
	}
}