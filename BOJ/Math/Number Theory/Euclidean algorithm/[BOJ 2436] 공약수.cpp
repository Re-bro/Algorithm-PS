/* [BOJ 2436] �����
	Algorithm : Euclidean Algorithm

	lcm(a, b) = a * b / gcd(a, b) ���� �̿�����. 
	�Է¹��� �� �� a, b�� ���� �� �ڿ����� ���̴�. 
	���� �� �ڿ����� ak, ������ �� �ڿ����� ab/(ak) = b/k��� �ϰ�
	k = 1���� gcd�� lcm�� ���� a�� b�� ������ üũ�Ѵ�.
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