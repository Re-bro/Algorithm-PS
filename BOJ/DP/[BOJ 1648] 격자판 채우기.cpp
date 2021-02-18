/* [BOJ 1648] 격자판 채우기
	Algorithm : Bit DP

	현재 칸을 (x, y)라고 한다면, (x, y) ~ (x, m) & (x+1, 1) ~ (x+1, y-1) 의 범위만 고려해주면 된다. 
	이외의 칸은 반드시 이미 모두 차있거나, 모두 비어있는 상태이다. 
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
int dp[200][1 << 15];
int n, m;
int sol(int idx, int state) {
	if (idx == n * m + 1) return state == 0 ? 1 : 0;
	int &ret = dp[idx][state];
	if (ret != -1) return ret;
	ret = 0;
	if (state & 1) ret += sol(idx + 1, state >> 1);
	else {
		if (!(idx%m == 0) && (state & 3) == 0) ret += sol(idx + 1, (state >> 1) + 1);
		ret += sol(idx + 1, (state >> 1) | (1 << (m - 1)));
	}
	ret %= 9901;
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	ini(dp, -1);
	cout << sol(1, 0);
}