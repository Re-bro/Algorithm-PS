/* [BOJ 1648] ������ ä���
	Algorithm : Bit DP

	���� ĭ�� (x, y)��� �Ѵٸ�, (x, y) ~ (x, m) & (x+1, 1) ~ (x+1, y-1) �� ������ ������ָ� �ȴ�. 
	�̿��� ĭ�� �ݵ�� �̹� ��� ���ְų�, ��� ����ִ� �����̴�. 
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