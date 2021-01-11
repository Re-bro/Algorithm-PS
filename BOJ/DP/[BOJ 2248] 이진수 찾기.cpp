/* [BOJ 2248] ������ ã��
	Algorithm : DP

	a�ڸ� �������� b�� ������ 1�� ��Ʈ�� ����� ����� ���� 
	aC0+ aC1 + ... + aCb �̴�.
	�̸� dp[a][b]�� �����صΰ�, ���� I���� dp[a-1][b]���� ũ�ٸ� a�ڸ����� 1�� �־��־�� �ϰ�, 
	�۴ٸ� 0�� �־��־�� �Ѵ�.
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[32][32];
ll combi[32][32];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll N, L, I; cin >> N >> L >> I;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) combi[i][j] = 1;
			else combi[i][j] = combi[i - 1][j - 1] + combi[i - 1][j];
		}
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= 31; j++) {
			for (int k = 0; k <= j; k++) dp[i][j] += combi[i][k];
		}
	}
	for (int i = N; i >= 1; i--) {
		if (L == 0) {
			cout << 0;
			continue;
		}
		if (dp[i - 1][L] < I) {
			cout << 1;
			I -= dp[i - 1][L];
			L--;
		}
		else cout << 0;
	}
}