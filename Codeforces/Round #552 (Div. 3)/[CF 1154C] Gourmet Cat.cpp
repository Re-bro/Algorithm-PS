/* [CF 1154C] Gourmet Cat
	Algorithm : Math

	��/��/�Ͽ��Ͽ��� fish��, ȭ/����Ͽ��� rabbit��, ��/�ݿ��Ͽ��� chicken�� �԰�,
	fish�� a��, rabbit�� b��, chicken�� c�� ���� ��, ���� ���� ���� �� �ֵ��� ������ ���� �����̴�.
	� ���Ϻ��� �����ϵ�, �׻� 7�ϵ����� fish�� 3��, rabbit�� chicken�� 2���� �Դ´�.
	���� �ּ� min(a/3, b/2, c/2) * 7�� ��ŭ�� ���� �� �ְ�, �������� ������ �󸶳� �� ���� �� �ִ��� Ȯ���Ѵ�.
	a, b, c�� ��� �ϳ��� 1������ ���� �ǹǷ� ���� �� �������� �ȴ�.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int A[7] = { 1, 2, 3, 1, 3, 2, 1 };
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll a, b, c; cin >> a >> b >> c;
	ll ans = 0;
	ll k = min({ a / 3, b / 2, c / 2 });
	a -= k * 3;
	b -= k * 2;
	c -= k * 2;
	for (int i = 0; i < 7; i++) {
		ll ta = a;
		ll tb = b;
		ll tc = c;
		ll cnt = 0;
		for (int j = i; ; j++) {
			if (A[j % 7] == 1) {
				if (ta == 0) break;
				else cnt++, ta--;
			}
			else if (A[j % 7] == 2) {
				if (tb == 0) break;
				else cnt++, tb--;
			}
			else {
				if (tc == 0) break;
				else cnt++, tc--;
			}
		}
		ans = max(ans, k * 7 + cnt);
	}
	cout << ans;
}