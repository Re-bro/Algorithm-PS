/* [BOJ 19576] 약수
	Algorithm : DP

	dp[i] = i를 최댓값으로 하고, i~n 범위가 약수가 되기 위한 와우 매직의 최소 사용 횟수
	dp[i] = min(dp[i], dp[j] + j-i-1)  if(a[i]%a[j] == 0)
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
int n;
int a[5001];
int dp[5001];
int sol(int idx) {
	int& ret = dp[idx];
	if (idx == n) return ret = 0;
	if (ret != -1) return ret;
	ret = n - idx;
	int cnt = 0;
	for (int i = idx + 1; i <= n; i++) {
		if (a[idx] % a[i] == 0) ret = min(ret, sol(i) + i - idx - 1);
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ini(dp, -1);
	sort(a + 1, a + 1 + n, greater<int>());
	for (int i = 1; i <= n; i++) sol(i);
	int ans = 10000;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, i - 1 + dp[i]);
	}
	cout << ans;
}