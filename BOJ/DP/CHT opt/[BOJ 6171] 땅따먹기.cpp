/* 
	[BOJ 6171] 땅따먹기
	Algorithm : Convex Hull Trick

	w 기준으로 내림차순을 한 후, 순서대로 탐색할 때 현재 h 값이 이전에 나온 h값의 최대보다 작다면
	현재 땅은 이전의 땅에 포함되는게 최적이다.
	따라서 포함되는 땅들을 모두 제거하면 w기준으로는 내림차순, h 기준으로는 오름차순으로 만들어진다.
	이후에는 점화식이 dp[i] = min(dp[j] + w[j+1]*h[i])  (j < i) 를 만족하기 때문에 
	Convex hull trick을 이용해주면 된다. 
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

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k > o.k; } // if you want min convex hull, using '>' as comparator
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = (ll)2e18;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b);
	}
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m < y->m ? inf : -inf; //if you want min convex hull, x->m < y->m ? inf : -inf
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({ k, m, 0 }), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
ll dp[50001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<pll> v;
	for (int i = 1; i <= n; i++) {
		ll w, h; cin >> w >> h;
		v.push_back({ w, h });
	}
	sort(all(v));
	reverse(all(v));
	LineContainer lc;
	ll last = 0;
	ll ans = 0;
	for (int i = 0; i < sz(v); i++) {
		if (last >= v[i].second) continue;
		last = v[i].second;
		lc.add(v[i].first, ans);
		ans = lc.query(v[i].second);
	}
	cout << ans;
}