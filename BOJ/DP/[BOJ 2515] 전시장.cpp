#include<bits/stdc++.h>
using namespace std;

int dp[505050];
int n, s;
vector<pair<int, int>> v;
int sol(int x) {
	int& ret = dp[x];
	if (ret != -1) return ret;
	ret = 0;
	int idx = lower_bound(v.begin(), v.end(), make_pair(v[x].first + s, 0)) - v.begin();
	if (idx == n + 1) return ret;
	int idx2 = lower_bound(v.begin(), v.end(), make_pair(v[idx].first + s, 0)) - v.begin();
	for (int i = idx; i < idx2; i++) {
		ret = max(ret, sol(i) + v[i].second);
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		int h, c; cin >> h >> c;
		v.push_back({ h, c });
	}
	v.push_back({ 0, 0 });
	sort(v.begin(), v.end());
	memset(dp, -1, sizeof(dp));
	cout << sol(0);
}