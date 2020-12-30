/* [BOJ 11635] Wipe Your Whiteboards
	Algorithm : Extended Euclidean Algorithm

	�������� $(A, B)$�� �ּҰ� �Ǿ�� �ϰ�, A�� B�� ��� 0���� Ŀ���ϱ� ������
	��Ŭ���� �˰����� ���� ���� A�� B�� ������ �������־�� �Ѵ�.
	�⺻������ $ax + by = c$�� �����ϴ� $(x, y)$�� ���� ��, $(x+b, y -a)$�� �ظ� �����ϴ� ���� �̿�����.
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

		//�� �� ����� �Ǳ� ���ؼ� ���ؾ��ϴ� �ּ� Ƚ��
		ll k = min((a-1) / ((-S)/g), (-b-1)/(R/g)); 
		a += k*S/g;
		b += k*R/g;
		cout << a << ' ' << -b << '\n';
	}
}