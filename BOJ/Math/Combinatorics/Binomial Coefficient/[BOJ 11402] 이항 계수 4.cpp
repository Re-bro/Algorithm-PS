/* [BOJ 11402] 이항 계수 4
	Algorithm : Lucas Theorem

	뤼카의 정리를 그대로 이용해주면 된다.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll fac[2001];
ll n, k, m;
ll mpow(ll a, ll cnt) {
	ll res = 1;
	while (cnt > 0) {
		if (cnt % 2) res = (res*a)%m;
		a = (a*a) % m;
		cnt /= 2;
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k >> m;
	fac[0] = 1;
	for (int i = 1; i <= m; i++) {
		fac[i] = fac[i - 1] * i % m;
	}
	ll ans = 1;
	while (n > 0 || k > 0) {
		int N = n % m;
		int K = k % m;
		if (K > N) {
			ans = 0; 
			break;
		}
		ans *= fac[N] * mpow(fac[K] * fac[N - K], m - 2) % m;
		ans %= m;
		n /= m;
		k /= m;
	}
	cout << ans;
}