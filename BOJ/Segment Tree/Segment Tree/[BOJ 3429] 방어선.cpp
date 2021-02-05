/* [BOJ 3429] 방어선
	Algorithm : Segment Tree

	dp[i] : 임의의 k (1<=k<=i-1)에 대해 [k ~ i-1]를 제거하거나 
				제거하지 않은 상태에서 A[i]를 끝으로 하는 최대 LIS
	dp2[i] : 아무도 제거하지 않았을 때 A[i]를 끝으로 하는 최대 LIS
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using pii = pair<int, int>;

int tr[800001];
int dp[200001];
int dp2[200001];
bool cmp(pii a, pii b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}
int update(int x, int s, int e, int i, int val) {
	if (i > e || i < s) return tr[x];
	if (s == e) return tr[x] = val;
	return tr[x] = max(update(x * 2, s, (s + e) / 2, i, val), update(x * 2 + 1, (s + e) / 2 + 1, e, i, val));
}
int qry(int x, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	else if (s >= l && e <= r) return tr[x];
	else return max(qry(x * 2, s, (s + e) / 2, l, r), qry(x * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		ini(tr, 0);
		ini(dp, 0);
		ini(dp2, 0);
		int n; cin >> n;
		vector<pii> v;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			v.push_back({ a, i + 1 });
		}
		sort(all(v), cmp);
		int ans = 0;
		for (auto[a, b] : v) {
			dp[b] = max({ 1, qry(1, 1, n, 1, b) + 1, dp[b - 1] + 1 });
			dp2[b] = dp2[b - 1] + 1;
			update(1, 1, n, b, dp2[b]);
			ans = max({ ans, dp[b], dp2[b] });
		}
		cout << ans << '\n';
	}
}