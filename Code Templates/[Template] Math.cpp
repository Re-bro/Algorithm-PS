#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//Extended Euclidean Algorithm
ll exEuclid(ll a, ll b, ll& s, ll& t) {
	if (b == 0) {
		s = 1; t = 0;
		return a;
	}
	ll gcd = exEuclid(b, a % b, s, t);
	ll tmp = t;
	t = s - (a / b) * t;
	s = tmp;

	if (s <= 0) { //s를 양수로
		s += b;
		t -= a;
	}
	return gcd;
}
//Euler-phi function
//phi(n) = n*(1-1/pi)*(1-1/p2)....*(1-1/pk)
ll phi(ll n) {
	ll res = n;
	if (n % 2 == 0) {
		res /= 2;
		while (n % 2 == 0) n /= 2;
	}
	for (ll i = 3; i*i <= n; i += 2) {
		if (n%i == 0) {
			res = res / i * (i - 1);
			while (n%i == 0) {
				n /= i;
			}
		}
	}
	if (n > 1) {
		res = res / n * (n - 1);
	}
	return res;
}

