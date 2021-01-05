/* [BOJ 17192] Snakes
	Algorithm : DP

	dp[i][k] = 최대 k번 사용하여 i ~ N까지의 그룹을 잡는 최소 횟수
	dp[i][k] = min(dp[j][k-1] + max(A[i] ~ A[j-1]) * (j-i) - sum(A[i] ~ A[j-1])) 
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
const int MAX = (int)2e9;
int A[410];
int dp[410][410];
int N, K;
int sol(int idx, int k) {
	if (idx == N + 1) return 0;
	if (k == -1) return 1e9;
	int& ret = dp[idx][k];
	if (ret != -1) return ret;
	ret = MAX;
	int mx = A[idx];
	int sum = A[idx];
	for (int i = idx + 1; i <= N+1; i++) {
		ret = min(ret, sol(i, k - 1) + mx * (i - idx) - sum);
		sum += A[i];
		mx = max(A[i], mx);
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> K;
	int total = 0;
	ini(dp, -1);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	cout << sol(1, K);
}