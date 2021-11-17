#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = (int)1e9 + 7;

#define MAX_C 3000000
ll fac[MAX_C+1], facinv[MAX_C+1];
ll mpow(ll a, ll x) { //a^x
	ll res = 1;
	while (x > 0) {
		if (x % 2) res *= a;
		res %= MOD;
		a = (a*a) % MOD;
		x /= 2;
	}
	return res;
}
ll combi(ll n, ll r) {
	return (((fac[n] * facinv[r]) % MOD)*facinv[n - r]) % MOD;
}
int main(void) {
	fac[0] = 1;
	for (int i = 1; i <= MAX_C; i++) fac[i] = (fac[i - 1] * i) % MOD;
	facinv[MAX_C] = mpow(fac[MAX_C], MOD - 2);
	for (int i = MAX_C-1; i >= 0; i--) facinv[i] = facinv[i + 1] * (i + 1) % MOD;

	cout << combi(n, r);
}
