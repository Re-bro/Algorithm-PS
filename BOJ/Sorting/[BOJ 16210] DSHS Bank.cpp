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

ll x[505050], y[505050], xsum[505050], ysum[505050];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	int n; cin >> n;
	vector<pll> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		v[i] = { x[i], y[i] };
	}
	sort(x + 1, x + 1 + n);
	sort(y + 1, y + 1 + n);
	for (int i = 1; i <= n; i++) {
		xsum[i] = xsum[i - 1] + x[i];
		ysum[i] = ysum[i - 1] + y[i];
	}
	ll mx = 1e18;
	int ans;
	for (int i = 1; i <= n; i++) {
		int xidx = lower_bound(x + 1, x + 1 + n, v[i].first) - x;
		int yidx = lower_bound(y + 1, y + 1 + n, v[i].second) - y;
		ll tmp1 = (xidx - 1) * v[i].first - xsum[xidx - 1] + (xsum[n] - xsum[xidx]) - (n-xidx)*v[i].first;
		ll tmp2 = (yidx - 1) * v[i].second - ysum[yidx - 1] + (ysum[n] - ysum[yidx]) - (n - yidx) * v[i].second;
		if (tmp1 + tmp2 < mx) {
			mx = tmp1 + tmp2;
			ans = i;
		}
	}
	cout << ans;
}