/*
	[BOJ 20648] Rectangular Pasture
	Algorithm : Segment Tree / Coordinate Compression / Sweeping
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

int tr[2501];
void update(int i) {
	while (i <= 2500) {
		tr[i]++;
		i += (i&-i);
	}
}
int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += tr[i];
		i -= (i&-i);
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<pii> v;
	vector<int> Y;
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		v.pb({ x, y });
		Y.pb(y);
	}
	sort(all(Y));
	sort(all(v));
	int N = sz(Y);
	for (int i = 0; i < n; i++) {
		v[i].fi = i + 1;
		v[i].se = lower_bound(all(Y), v[i].se) - Y.begin() + 1;
	}
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		ini(tr, 0);
		for (int j = i; j < n; j++) {
			update(v[j].se);
			int mi = min(v[i].second, v[j].second);
			int mx = max(v[i].second, v[j].second);
			ans += 1LL*sum(mi) * (sum(N) - sum(mx-1));
		}
	}
	cout << ans;
}