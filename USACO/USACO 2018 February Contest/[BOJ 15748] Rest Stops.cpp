/*
	[BOJ 15748] Rest Stops
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
const int MAX = (int)2e9;
const double PI = acos(-1);

ll x[101010], c[101010], order[101010], mi[101010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	ll L, N, rF, rB; cin >> L >> N >> rF >> rB;
	vector<pll> v;
	for (int i = 1; i <= N; i++) {
		cin >> x[i] >> c[i];
		v.pb({ c[i], i });
	}
	sort(all(v), greater<pll>());
	for (int i = 0; i < sz(v); i++) {
		order[v[i].se] = i + 1;
	}
	mi[N + 1] = MAX;
	for (int i = N; i >= 1; i--) {
		mi[i] = min(mi[i + 1], order[i]);
	}
	ll ans = 0;
	ll diff = 0;
	for (int i = 1; i <= N; i++) {
		diff += (x[i] - x[i - 1])*(rF - rB);
		if (mi[i] == order[i]) {
			ans += diff * c[i];
			diff = 0;
		}
	}
	cout << ans;
}