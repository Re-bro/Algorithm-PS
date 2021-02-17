/* 
	[BOJ 15678] 연세워터파크
	Algorithm : Deque DP or Segment Tree
	
	dp[i] = i번째를 마지막으로 밟을 때 최대
	dp[i] = max(dp[i-d] ~ dp[i-1]) + A[i]
*/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int MAX = (int)2e9;

ll dp[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n, d; cin >> n >> d;
	deque<pair<ll, int>> dq;
	for (int i = 1; i <= n; i++) {
		ll a; cin >> a;
		if (!dq.empty()) dp[i] = max(0LL, dq.front().first);
		dp[i] += a;
		while (!dq.empty() && (dq.front().first <= dp[i] || dq.front().second < i - d + 1)) dq.pop_front();
		while (!dq.empty() && (dq.back().first <= dp[i] || dq.back().second < i - d + 1)) dq.pop_back();
		dq.push_back({ dp[i], i });
	}
	ll ans = -MAX;
	for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans;
}