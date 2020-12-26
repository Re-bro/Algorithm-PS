/* [BOJ 16468] 크리스마스 트리 꾸미기
	Algorithm : DP

	dp[n][k][i] : k개의 공으로 높이가 n인 트리를 채우는 경우의 수
	i = 0 :  높이가 다 안채워진 경우 , i = 1 : 높이가 다 채워진 경우
	현재 노드를 루트로 하는 서브트리가 높이가 다 채워지기 위해서는 
	두 자손 중 적어도 하나는 다 채워져야 한다.
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