/*
	[BOJ 15752] Hoofball
	Algorithm : DP
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
#define fi first
#define se second

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);

int a[110];
int dp[110];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	a[0] = -10000;
	a[n + 1] = 10000;
	vector<pii> v;
	for (int i = 1; i <= n; i++) {
		vector<bool> visited(n + 1);
		int s = i;
		while (!visited[s]) {
			visited[s] = true;
			if (a[s] - a[s - 1] <= a[s + 1] - a[s]) {
				s--;
			}
			else s++;
		}
		int l = MAX;
		int r = 0;
		for (int j = 1; j <= n; j++) {
			if (visited[j]) {
				l = min(l, j);
				r = max(r, j);
			}
		}
		v.pb({ l, r });
	}
	sort(all(v));
	dp[0] = 0;
	for (int i = 1; i <= n; i++) dp[i] = MAX;
	for (int i = 0; i < sz(v); i++) {
		for (int j = v[i].first; j <= v[i].second; j++) {
			dp[j] = min(dp[v[i].first-1] + 1, dp[j]);
		}
	}
	cout << dp[n];
}