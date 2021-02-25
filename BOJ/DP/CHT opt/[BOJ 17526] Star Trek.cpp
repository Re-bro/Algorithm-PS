/*
	[BOJ 17526] Star Trek
	Algorithm : DP / Convex Hull Trick

	dp[i] = min(dp[j] + prepare[j] + len(j ~ i)*speed[j]) (j < i)
			= min(s[j]*d[i] + dp[j] + p[j] - d[j]*s[j]) (j < i)
	꼴로 나타나므로 컨벡스헐 트릭을 이용해줄 수 있다. 
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

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
ll d[100001];
ll p[100001];
ll s[100001];
ll dp[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> d[i];
		d[i] += d[i - 1];
	}
	for (int i = 1; i < n; i++) {
		cin >> p[i] >> s[i];
	}
	LineContainer lc;
	lc.add(s[1], dp[1] + p[1] - d[1] * s[1]);
	for (int i = 2; i <= n; i++) {
		dp[i] = lc.query(d[i]);
		lc.add(s[i], dp[i] + p[i] - d[i] * s[i]);
	}
	cout << dp[n];
}