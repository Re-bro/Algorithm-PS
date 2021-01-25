/* [BOJ 1757] �޷��޷�
	Algorithm : DP

	dp[i][j] = i��° ��ġ���� j�� ��ħ������ ���� �� �ִ��� �ָ� �� �� �ִ� �Ÿ�
	i���� �޸��� ��� dp[i][j] = max(dp[i][j], dp[i+1][j+1] + d[i])
	i���� ���� ��� dp[i][j] = max(dp[i][j], dp[i+j][0])
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
const int MAX = (int)2e9;

int dp[10001][501];
int d[10001];
int n, m;

int sol(int pos, int k) {
	if (pos == n) return k == 0 ? 0 : -MAX;
	int &ret = dp[pos][k];
	if (ret != -1) return ret;
	ret = -MAX;
	if (k < m) ret = max(ret, sol(pos + 1, k + 1) + d[pos + 1]);
	if (k == 0) ret = max(ret, sol(pos + 1, k));
	if (k > 0 && pos+k <=n) ret = max(ret, sol(pos + k, 0));
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	ini(dp, -1);
	for (int i = 1; i <= n; i++) cin >> d[i];
	cout << sol(0, 0);
}