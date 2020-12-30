/* [BOJ 14565] 역원(Inverse)구하기
	Algorithm : Extended Euclid algorithm 

	덧셈역은 n-a이고, 곱셈역은 ac + nk = 1 을 만족하는 (c, k) 해를 구해주면 된다.
	c가 양수가 나오도록 해주는 것을 주의하자.
*/

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
	return gcd;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	ll n, a; cin >> n >> a;
	ll c, k;
	ll g = exEuclid(a, n, c, k);
	if (g != 1) cout << n - a << ' ' << -1;
	else cout << n - a << ' ' << c;
}