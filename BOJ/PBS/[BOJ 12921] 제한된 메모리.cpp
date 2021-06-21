/*
	[BOJ 12921] 제한된 메모리
	Algorithm : PBS
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int Q[1010], L[1010], R[1010], cnt[1010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll n, x0, a, b; cin >> n >> x0 >> a >> b;
	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> Q[i];
		L[i] = 0;
		R[i] = (int)1e9 + 9;
	}
	while (1) {
		vector<pll> v;
		ini(cnt, 0);
		for (int i = 1; i <= q; i++) {
			if (L[i] < R[i]) {
				v.push_back({ (L[i] + R[i]) / 2, i });
			}
		}
		ll x = x0;
		if (sz(v) == 0) break;
		sort(all(v));
		for (int i = 0; i < n; i++) {
			int idx = lower_bound(all(v), make_pair(x, 0LL)) - v.begin();
			cnt[idx]++;
			x = (x * a + b) % 1000000007;
		}
		for (int i = sz(v); i >= 1; i--) {
			cnt[i] += cnt[i + 1];
			if (Q[v[i-1].second] + 1 <= n-cnt[i]) {
				R[v[i-1].second] = v[i-1].first;
			}
			else L[v[i-1].second] = v[i-1].first + 1;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= q; i++) {
		ans += L[i];
	}
	cout << ans;
}