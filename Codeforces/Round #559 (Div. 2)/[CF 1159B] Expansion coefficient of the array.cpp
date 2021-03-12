/*
	[CF 1159B] Expansion coefficient of the array
	Algorithm : math
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll a[300001];
vector<pii> v;
int n;
bool sol(ll m) {
	for (int i = 0; i < sz(v); i++) {
		if (m * (ll)max(n - v[i].second, v[i].second - 1) > v[i].first) return false;
	}
	return true;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v.push_back({ a[i], i });
	}
	sort(all(v));
	ll s = 0;
	ll e = 1e10;
	ll ans = 0;
	while (s <= e) {
		ll mid = (s + e) / 2;
		if (sol(mid)) {
			ans = max(ans, mid);
			s = mid + 1;
		}
		else e = mid - 1;
	}
	cout << ans;
}