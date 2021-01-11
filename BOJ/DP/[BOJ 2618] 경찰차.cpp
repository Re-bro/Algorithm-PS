/* [BOJ 2618] 경찰차
	Algorithm : DP

	dp[a][b] = 경찰차 1이 a까지, 경찰차 2가 b까지 이동했을 때, 이후 이동거리의 최솟값
	다음 사건을 next = max(a,b) + 1이라고 하면, 
	dp[a][b] = min(dp[a][next] + dist(b, next) , dp[next][b] + dist(a, next))
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
using pii = pair<int, int>;
int N, W; 
int dp[1010][1010];
pii v[1010];
int dist(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int sol(int a, int b) {
	int &ret = dp[a][b];
	if (max(a, b) == W+2) return ret = 0;
	if (ret != -1) return ret;
	int next = max(a, b) + 1;
	ret = min(sol(next, b) + dist(v[a], v[next]), sol(a, next) + dist(v[b], v[next]));
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> W;
	for (int i = 3; i <= W+2; i++) {
		cin >> v[i].first >> v[i].second;
	}
	v[1] = { 1, 1 };
	v[2] = { N, N };
	ini(dp, -1);
	cout<< sol(1, 2)<<'\n';
	int a = 1, b = 2;
	for (int i = 3; i <= W + 2; i++) {
		if (dp[a][i] + dist(v[b], v[i]) == dp[a][b]) cout << 2 << '\n', b = i;
		else cout << 1 << '\n', a = i;
	}
}