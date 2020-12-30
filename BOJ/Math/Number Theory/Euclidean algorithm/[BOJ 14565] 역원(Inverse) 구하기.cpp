/* [BOJ 14565] ����(Inverse)���ϱ�
	Algorithm : Extended Euclid algorithm 

	�������� n-a�̰�, �������� ac + nk = 1 �� �����ϴ� (c, k) �ظ� �����ָ� �ȴ�.
	c�� ����� �������� ���ִ� ���� ��������.
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
	return gcd;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	ll n, a; cin >> n >> a;
	ll c, k;
	ll g = exEuclid(a, n, c, k);
	if (g != 1) cout << n - a << ' ' << -1;
	else cout << n - a << ' ' << c;
}