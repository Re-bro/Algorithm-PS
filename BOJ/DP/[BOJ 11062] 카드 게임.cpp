/* [BOJ 11062] ī�� ����
	Algorithm : DP

	dp[i][j][k]
	k = 0 : �ٿ� ���� / k = 1 : ��� ����
	�ٿ츦 �������� ����, ��� ���ʿ��� ��찡 �ּ��� �������� ���ϹǷ� 
	�� �� �� ���� ���� �ٿ찡 ��������. 
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
int dp[1001][1001][2];
int a[1001];
int sol(int l, int r, int turn) {
	if (l == r) {
		if (turn == 0) return a[l];
		else return 0;
	}
	int &ret = dp[l][r][turn];
	if (ret != -1) return ret;
	ret = 0;
	if (turn == 0) {
		ret = max(sol(l + 1, r, 1) + a[l], sol(l, r - 1, 1) + a[r]);
	}
	else ret = min(sol(l + 1, r, 0), sol(l, r - 1, 0));
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		ini(dp, -1);
		cout << sol(1, n, 0)<<'\n';
	}
}