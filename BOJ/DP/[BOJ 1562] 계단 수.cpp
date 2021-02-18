/* 
	[BOJ 1562] °è´Ü ¼ö
	Algorithm : Bit DP
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
using ll = long long;
const int MOD = (int)1e9;

ll dp[101][10][1 << 10];
int n;
ll sol(int idx, int now, int state) {
	if (idx == n) {
		if (state == (1 << 10) - 1) return 1;
		else return 0;
	}
	ll &ret = dp[idx][now][state];
	if (ret != -1) return ret;
	ret = 0;
	if (idx == 0) {
		for (int i = 1; i <= 9; i++) ret += sol(idx + 1, i, 1 << i);
	}
	else {
		if (now > 0) ret += sol(idx + 1, now - 1, state | (1 << (now - 1)));
		if (now < 9) ret += sol(idx + 1, now + 1, state | (1 << (now + 1)));
	}
	ret %= MOD;
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	ini(dp, -1);
	cout << sol(0, 0, 0);
}