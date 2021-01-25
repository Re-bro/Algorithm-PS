/* [BOJ 11066] ���� ��ġ��
	Algorithm : DP

	dp[i][j] := [i, j] ������ ��� ��ġ�µ� �ʿ��� �ּ� ���
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;

int psum[501];
int dp[501][501];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int k; cin >> k;
		for (int i = 1; i <= k; i++) {
			int a; cin >> a;
			psum[i] = psum[i - 1] + a;
			for (int j = 1; j <= k; j++) 
			if (i != j) {
				dp[i][j] = MAX;
			}
			else dp[i][j] = 0;
		}
		for (int i = 1; i < k; i++) {
			for (int j = 1; j <= k-i; j++) {
				for (int q = j; q < j+i; q++) {
					dp[j][j + i] = min(dp[j][j + i], dp[j][q] + dp[q+1][j + i] + psum[j+i] - psum[j-1]);
				}
			}
		}
		cout << dp[1][k]<< '\n';
	}
}