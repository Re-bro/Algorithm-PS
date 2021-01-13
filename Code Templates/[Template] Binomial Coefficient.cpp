///////////////////// binomial coefficient O(n + logp)/////////////////
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;

#define MN 4000000
ll fac[MN+10], facinv[MN+10];
ll mpow(ll a, ll x) {
	ll res = 1;
	while (x > 0) {
		if (x % 2) res = (res*a) % MOD;
		a = (a*a) % MOD;
		x /= 2;
	}
	return res;
}
void fac_init() {
	fac[0] = 1;
	for (int i = 1; i <= MN; i++) fac[i] = fac[i - 1] * i % MOD;
	facinv[MN] = mpow(fac[MN], MOD - 2);
	for (int i = MN - 1; i >= 0; i--) facinv[i] = facinv[i + 1] * (i + 1) % MOD;
}
ll C(ll n, ll r) {
	return ((fac[n] * facinv[r]) % MOD) * facinv[n - r] % MOD;
}
int main(void) {
	ll n, r;
	fac_init();
	cout << C(n, r);
}


///////////////////////////Lucas Theorem //////////////////////////////
// O(P)

#include<bits/stdc++.h>
#define MAX_P 2001
using namespace std;
using ll = long long;
const int MOD = 7;
ll fac[MAX_P];

ll mpow(ll a, ll k, ll mod) {
	ll res = 1;
	while (k > 0) {
		if (k % 2) res = (res * a) % mod;
		a = (a*a) % mod;
		k /= 2;
	}
	return res;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll n, r;
	ll ans = 1;
	while (n || r) {
		int N = n % MOD;
		int R = r % MOD;
		if (R > N) {
			ans = 0;
			break;
		}
		ans *= fac[N] * mpow(fac[R] * fac[N - R], MOD - 2, MOD) % MOD;
		ans %= MOD;
		n /= MOD;
		r /= MOD;
	}
	cout << ans;
}

