/*
	[BOJ 22354] 돌 가져가기
	Algorithm : Greedy / Sorting
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
const int MAX = (int)1e9;
const double PI = acos(-1);

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	string s; cin >> s;
	vector<ll> v;
	ll mx = 0;
	for (int i = 0; i < n; i++) {
		ll k; cin >> k;
		mx = max(mx, k);
		if (i == n-1|| s[i] != s[i + 1]) {
			v.pb(mx);
			mx = 0;
		}
	}
	ll ans = 0;
	if (sz(v) <= 2) return cout << 0, 0;
	sort(v.begin() + 1, v.end()-1, greater<int>());
	for (int i = 1; i <= (sz(v)-1) / 2 ; i++) {
		ans += v[i];
	}
	cout << ans;

}