#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;

#define MN 2000000
ll fac[MN + 10], facinv[MN + 10];
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
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	fac_init();
	int n, m, k; cin >> n >> m >> k;
	if (n > m + k) cout << 0;
	else cout << (MOD + C(n + m, n) - C(n + m, m + k + 1)) % MOD;
}