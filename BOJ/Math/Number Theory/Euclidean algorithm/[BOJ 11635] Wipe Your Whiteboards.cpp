/* [BOJ 11635] Wipe Your Whiteboards
	Algorithm : Extended Euclidean Algorithm

	구해지는 $(A, B)$가 최소가 되어야 하고, A와 B가 모두 0보다 커야하기 때문에
	유클리드 알고리즘을 통해 나온 A와 B를 적절히 조절해주어야 한다.
	기본적으로 $ax + by = c$를 만족하는 $(x, y)$가 있을 때, $(x+b, y -a)$도 해를 만족하는 점을 이용하자.
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
		ll k = (-s) / b + 1;
		s += k*b;
		t -= k*a;
	}

	return gcd;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		ll R, S, Q; cin >> R >> S >> Q;
		ll a, b;
		ll g = exEuclid(R, -S, a, b);
		a *= Q / g;
		b *= Q / g;

		//둘 다 양수가 되기 위해서 곱해야하는 최소 횟수
		ll k = min((a-1) / ((-S)/g), (-b-1)/(R/g)); 
		a += k*S/g;
		b += k*R/g;
		cout << a << ' ' << -b << '\n';
	}
}