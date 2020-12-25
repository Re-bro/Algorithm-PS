/* [BOJ 1234] 크리스마스 트리
	Algorithm : DP / Combinatorics

	각 레벨에서 조건을 만족시킬 수 있는 경우에, 같은 것이 있는 순열을 이용해서 경우의 수를 곱해주면 된다.
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using ll = long long;
ll ans = 0;
int N;
ll fac[11];
ll dp[11][56][56][56];
ll sol(int lv, int a, int b, int c) {
	ll& ret = dp[lv][a][b][c];
	if (lv == N) {
		return 1;
	}
	if (ret != -1) return ret;
	ret = 0;
	if (a >= lv + 1) ret += sol(lv + 1, a - lv - 1, b, c);
	if (b >= lv + 1) ret += sol(lv + 1, a, b - lv - 1, c);
	if (c >= lv + 1) ret += sol(lv + 1, a, b, c - lv - 1);
	int k = (lv + 1) / 3;
	if (a >=k && b >=k && c >=k && (lv + 1) % 3 == 0) {
		ret += sol(lv + 1, a - k, b - k, c - k) * (fac[3 * k] / (fac[k] * fac[k] * fac[k]));
	}
	if ((lv + 1) % 2 == 0) {
		k = (lv + 1) / 2;
		if (a >= k && b >= k) ret += sol(lv + 1, a - k, b - k, c) * (fac[2 * k] / (fac[k] * fac[k]));
		if (b >= k && c >= k) ret += sol(lv + 1, a, b - k, c - k) * (fac[2 * k] / (fac[k] * fac[k]));
		if (a >= k && c >= k) ret += sol(lv + 1, a - k, b, c - k) * (fac[2 * k] / (fac[k] * fac[k]));
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N;
	fac[0] = 1;
	for (int i = 1; i <= 10; i++) fac[i] = fac[i - 1] * i;
	ini(dp, -1);
	int a, b, c; cin >> a >> b >> c;
	cout << sol(0, min(a, 55), min(b, 55), min(c, 55));
}