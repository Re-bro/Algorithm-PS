/* [BOJ 2248] 이진수 찾기
	Algorithm : DP

	a자리 이진수를 b개 이하의 1인 비트로 만드는 경우의 수는 
	aC0+ aC1 + ... + aCb 이다.
	이를 dp[a][b]에 저장해두고, 현재 I값이 dp[a-1][b]보다 크다면 a자리에는 1을 넣어주어야 하고, 
	작다면 0을 넣어주어야 한다.
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