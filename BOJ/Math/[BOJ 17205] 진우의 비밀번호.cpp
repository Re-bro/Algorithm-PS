/*
	[BOJ 17205] 진우의 비밀번호
	Algorithm : Math
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
ll dp[11];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	int n; string s; cin >> n >> s;
	ll ans = 0;
	for (int i = 1; i <= 10; i++) {
		dp[i] = (dp[i - 1] + 1) * 26;
	}
	for (int i = 0; i < sz(s); i++) {
		ans += (dp[n - i - 1] + 1) * (s[i] - 'a');
		ans++;
	}
	cout << ans;
}