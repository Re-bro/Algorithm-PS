#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll exEuclid(ll a, ll b, ll &s, ll &t) {
	if (b == 0) {
		s = 1; t = 0;
		return a;
	}
	ll gcd = exEuclid(b, a%b, s, t);
	ll temp = t;
	t = s - (a / b)*t;
	s = temp;

	if (s <= 0) {
		s += b;
		t -= a;
	}
	if (t == 0) {
		s += b;
		t -= a;
	}
	return gcd;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		ll k, c; cin >> k >> c;
		ll n, x; 
		ll g = exEuclid(c, k, n, x);
		if (g != 1 || n >(ll)1e9) cout << "IMPOSSIBLE\n";
		else cout << n << '\n';
	}
}