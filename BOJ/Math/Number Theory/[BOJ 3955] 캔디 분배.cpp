/* [BOJ 3955] 캔디 분배
	Algorithm : Extended Euclidean Algorithm

	KX + 1 = CN을 만족하는 N과 X를 찾아줘야 한다. 
	따라서 CN - KX = 1을 만족하는 방정식을 풀어주어야 하므로 
	먼저 gcd(C, K)가 1이 되어야 한다.
	그리고 X가 자연수가 되어야 하므로 X가 0으로 나오는 경우에는 자연수로 만들어준다. 
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
		s += b;
		t -= a;
	}
	if (t == 0) {
		s += b;
		t -= a;
	}
	return gcd;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		ll k, c; cin >> k >> c;
		ll n, x; 
		ll g = exEuclid(c, k, n, x);
		if (g != 1 || n >(ll)1e9) cout << "IMPOSSIBLE\n";
		else cout << n << '\n';
	}
}