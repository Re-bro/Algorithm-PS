#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int miller_base[] = { 2,3,5,7,11,13,17, 19,23,29,31,37 }; // long long 기준
int miller_base[] = { 2, 7, 61 }; // int 기준
ll mpow(ll x, ll y, ll mod) { //x^y (mod)
	ll res = 1;
	x %= mod;
	while (y) {
		if (y % 2) res = (res*x) % mod; //mod가 10^9 넘는 경우에는 res앞에 (__int128) 넣어주기
		y /= 2;
		x = (x*x) % mod;
	}
	return res;
}
//if n is composite = false. prime = true
bool miller(ll n, ll a) {
	if (n <= 1) return false; 
	if (a%n == 0) return true; //판별하는 a가 모두 소수이므로 n도 소수
	ll k = n - 1;
	while (1) {
		ll tmp = mpow(a, k, n); //a^k
		if (tmp == n - 1) return true; //a^k = -1 (mod n)
		if (k % 2) { //더이상 루트를 씌워줄 수 없는 상태. 소수이면 a^k = 1 또는 -1이 되어야 함.
			return (tmp == 1 || tmp == n - 1);
		}
		k /= 2;
	}
}
bool isprime(ll a) {
	for (int i = 0; i < miller_base.size(); i++) {
		if (miller(a, miller_base[i]) == false) return false;
	}
	return true;
}
int main(void) {
	ll n; cin >> n;
	if (isprime(n)) cout << "Prime!";
	else cout << "Composite!";
}
