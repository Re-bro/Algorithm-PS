/* [BOJ 7579] ¾Û
	Algorithm : DP / knapsack

*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll m[101];
ll c[101];
ll dp[10001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	ll M; cin >> M;
	for (int i = 1; i <= N; i++) {
		cin >> m[i];
	}
	for (int i = 1; i <= 10000; i++) dp[i] = -1;
	for (int i = 1; i <= N; i++) cin >> c[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 10000; j >= c[i]; j--) {
			if (dp[j - c[i]] != -1) dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
		}
	}
	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= M) return cout << i, 0;
	}
}