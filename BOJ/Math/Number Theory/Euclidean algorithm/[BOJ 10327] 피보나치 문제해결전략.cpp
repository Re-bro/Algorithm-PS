/* [BOJ 10327] 피보나치 문제해결전략
	Algorithm : Extended Euclidean Algorithm

	G1 = a, G2 = b라고 하고, 원래의 피보나치 수열을 fibo[i]라고 하면
	Gabonacci 수열은 fibo[i]*a + fibo[i+1]*b의 형태로 나타난다. 
	따라서 가능한 모든 fibo[i]*a + fibo[i+1]*b = n의 방정식의 해를 구해서
	그 중, 가장 작은 해를 구한다.
	overflow에 주의하자.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
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
ll fibo[100];
ll ceil(ll a, ll b) {
	return (a + b - 1) / b;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	fibo[1] = 1;
	int r;
	for (int i = 2; i < 100; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		r = i;
		if (fibo[i] > 5e8) break;
	}
	while (T--) {
		ll n; cin >> n;
		ll x = 1e10;
		ll y = 1e10;
		for (int i = 0; i < r; i++) {
			ll a, b;
			ll g = exEuclid(fibo[i], fibo[i + 1], a, b);
			if ((n % g) != 0) continue;
			a *= n / g;
			b *= n / g;
			ll k = ceil(a - b, (fibo[i] + fibo[i + 1]) / g);
			b += k * (fibo[i] / g);
			a -= k * (fibo[i + 1] / g);
			if (a>0 && a <=b && (b < y || (b == y && a < x))) {
				x = a;
				y = b;
			}
		}
		cout << x << ' ' << y << '\n';
	}
}