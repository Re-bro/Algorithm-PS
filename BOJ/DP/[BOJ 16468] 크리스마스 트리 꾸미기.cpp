/* [BOJ 16468] ũ�������� Ʈ�� �ٹ̱�
	Algorithm : DP

	dp[n][k][i] : k���� ������ ���̰� n�� Ʈ���� ä��� ����� ��
	i = 0 :  ���̰� �� ��ä���� ��� , i = 1 : ���̰� �� ä���� ���
	���� ��带 ��Ʈ�� �ϴ� ����Ʈ���� ���̰� �� ä������ ���ؼ��� 
	�� �ڼ� �� ��� �ϳ��� �� ä������ �Ѵ�.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 100030001;


ll dp[301][301][2];
bool visited[301][301][2];
void sol(int n, int k) {
	if (n == 1) return;
	if (visited[n][k][0]) return;
	for (int i = 0; i < k; i++) {
		if (n <= 10 && i >= (1 << (n - 1))) break;
		sol(n - 1, i);
	}
	for (int i = 0; i < k; i++) {
		dp[n][k][1] += dp[n - 1][i][0] * dp[n - 1][k - i - 1][1] + dp[n - 1][i][1] * dp[n - 1][k - i - 1][0] + dp[n - 1][i][1] * dp[n - 1][k - i - 1][1];
		dp[n][k][1] %= MOD;
		dp[n][k][0] += dp[n - 1][i][0] * dp[n - 1][k - i - 1][0];
		dp[n][k][0] %= MOD;
	}
	visited[n][k][0] = true;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, L; cin >> N >> L;
	dp[1][1][1] = 1;
	for (int i = 1; i <= N; i++) {
		dp[i][0][0] = 1;
	}
	sol(L, N);
	cout << dp[L][N][1];
}