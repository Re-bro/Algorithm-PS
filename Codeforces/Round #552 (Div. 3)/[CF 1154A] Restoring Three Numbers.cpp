/* [CF 1154A] Restoring Three Numbers
	Algorithm : Math

	�Է����� a+b, a+c, b+c, a+b+c�� ���� ������ ���´�.
	�̸� �� ���ϸ� 3(a+b+c) �̹Ƿ�, a+b+c�� ���� ������ �� �ִ�.
	���� ���� a+b+c�� ���� ������ �Է��� ã�� ��, �ش� �Է¿��� ������ �� �Է��� ���ָ� ���� a,b,c�� ���´�.
*/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll a, b, c, d; cin >> a >> b >> c >> d;
	ll total = a + b + c + d;
	total /= 3;
	if (a == total) {
		cout << a - b << ' ' << a - c << ' ' << a - d;
	}
	else if (b == total) {
		cout << b - a << ' ' << b - c << ' ' << b - d;
	}
	else if (c == total) {
		cout << c - a << ' ' << c - b << ' ' << c - d;
	}
	else cout << d - a << ' ' << d - b << ' ' << d - c;

}