/* [BOJ 2436] 공약수
	Algorithm : Euclidean Algorithm

	lcm(a, b) = a * b / gcd(a, b) 임을 이용하자. 
	입력받은 두 수 a, b의 곱이 두 자연수의 곱이다. 
	따라서 한 자연수를 ak, 나머지 한 자연수를 ab/(ak) = b/k라고 하고
	k = 1부터 gcd와 lcm이 각각 a와 b와 같은지 체크한다.
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll a, b; cin >> a >> b;
	ll mul = a*b;
	ll ax, ay;
	for (ll x = a; ; x += a) {
		ll y = mul / x;
		if (x > y) break;
		ll g = gcd(x, y);
		if (g == a && x*y / g == b) {
			ax = x;
			ay = y;
		}
	}
	cout << ax << ' ' << ay;
}