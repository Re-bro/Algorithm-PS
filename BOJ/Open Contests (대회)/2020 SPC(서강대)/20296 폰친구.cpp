/* [BOJ 20296] 폰친구
	Algorithm : Math, Combinatorics , Fermat's little Thm

	풀이 : https://wogud6792.tistory.com/78
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
ll N, m, M, K;
#define MAX_C 1005000
ll fac[MAX_C + 1], facinv[MAX_C + 1];
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
void make_fac(void) {
	fac[0] = 1;
	for (int i = 1; i <= MAX_C; i++) fac[i] = (fac[i - 1] * i) % MOD;
	facinv[MAX_C] = mpow(fac[MAX_C], MOD - 2);
	for (int i = MAX_C - 1; i >= 0; i--) facinv[i] = facinv[i + 1] * (i + 1) % MOD;
}
ll combi(ll n, ll r) {
	return (((fac[n] * facinv[r]) % MOD)*facinv[n - r]) % MOD;
}
ll H(ll n, ll r) {
	return combi(n + r - 1, r);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N >> m >> M >> K;
	K -= N*m;
	M -= m;
	make_fac();
	ll ans = combi(N + K - 1, K);
	for (int i = 1; i <= N; i++) {
		if (K - (M + 1)*i >= 0) ans += (ll)pow(-1, i)*(H(N, K - (M + 1)*i)*combi(N, i))%MOD;
		else break;
		ans = (ans + MOD) % MOD;
	}
	cout << ans;
}