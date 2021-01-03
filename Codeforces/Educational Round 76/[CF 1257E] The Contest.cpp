/* [CF 1257E] The Contest
	Algorithm : DP

	1, 2, 3���� �̷���� ������ �־��� ��, 1....12....23...3 �� ���� ������ֱ� ���� �ּ� ���� Ƚ���� ���ϴ� �����̴�.
	��, ���� ���ڳ����� �׻� �̿��ؾ��ϰ� ���������� �����ؾ� �Ѵٴ� �ǹ��̴�.
	���⼭ �ݵ�� 1,2,3�� ��� ���� �ʿ�� ����.
	dp[i][j] = A[i] = j�̸鼭 ���� ������ �����ϴ� i��° ���ұ����� �ּ� ���� Ƚ����� �ϸ�,
	dp[i][1]�� �տ� �׻� 1�� �;��ϹǷ� dp[i-1][1]�� ��������,
	dp[i][2]�� �տ� 1 �Ǵ� 2�� �� �� �����Ƿ� dp[i-1][1], dp[i-1][2]�� ��������,
	dp[i][3]�� �տ� � ���� �͵� ��������Ƿ� dp[i-1][1], dp[i-1][2], dp[i-1][3] ��� �����´�.
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;

int num[200001];
int dp[200001][4];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int k1, k2, k3; cin >> k1 >> k2 >> k3;
	int n = k1 + k2 + k3;
	for (int i = 1; i <= k1; i++) {
		int a; cin >> a;
		num[a] = 1;
	}
	for (int i = 1; i <= k2; i++) {
		int a; cin >> a;
		num[a] = 2;
	}
	for (int i = 1; i <= k3; i++) {
		int a; cin >> a;
		num[a] = 3;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			dp[i][j] = MAX;
			for (int k = 1; k <= j; k++) {
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + (j != num[i] ? 1 : 0));
			}
		}
	}
	cout << min({ dp[n][1], dp[n][2], dp[n][3] });
}