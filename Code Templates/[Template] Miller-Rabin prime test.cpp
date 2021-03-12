#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int miller_base[] = { 2,3,5,7,11,13,17, 19,23,29,31,37 }; // long long ����
int miller_base[] = { 2, 7, 61 }; // int ����
ll mpow(ll x, ll y, ll mod) { //x^y (mod)
	ll res = 1;
	x %= mod;
	while (y) {
		if (y % 2) res = (res*x) % mod; //mod�� 10^9 �Ѵ� ��쿡�� res�տ� (__int128) �־��ֱ�
		y /= 2;
		x = (x*x) % mod;
	}
	return res;
}
//if n is composite = false. prime = true
bool miller(ll n, ll a) {
	if (n <= 1) return false; 
	if (a%n == 0) return true; //�Ǻ��ϴ� a�� ��� �Ҽ��̹Ƿ� n�� �Ҽ�
	ll k = n - 1;
	while (1) {
		ll tmp = mpow(a, k, n); //a^k
		if (tmp == n - 1) return true; //a^k = -1 (mod n)
		if (k % 2) { //���̻� ��Ʈ�� ������ �� ���� ����. �Ҽ��̸� a^k = 1 �Ǵ� -1�� �Ǿ�� ��.
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
