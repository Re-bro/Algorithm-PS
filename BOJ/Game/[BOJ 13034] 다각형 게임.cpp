/*
	[BOJ 13034] 다각형 게임
	Algorithm : Game / Sprague grundy
*/
#include<bits/stdc++.h>
using namespace std;

int dp[1001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	dp[0] = dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		vector<bool> chk(n);
		for (int j = 0; j <= i-2; j++) {
			chk[dp[j] ^ dp[i - 2 - j]] = true;
		}
		for (int j = 0; j < n; j++) {
			if (!chk[j]) {
				dp[i] = j;
				break;
			}
		}
	}
	if (dp[n]) cout << 1;
	else cout << 2;
}