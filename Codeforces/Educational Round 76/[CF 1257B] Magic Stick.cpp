/* [CF 1257B] Magic Stick
	Algorithm : math

	x�� y���� ũ�ų� ������ �׻� -1�� �ٿ������� y�� ���� �� �ִ�.
	x�� y���� ���� ��� �߿�����, x = 2�̰� y = 3�� ��쿡 �����ϴ�.
	�� x�� 4�̻��� ��쿡�� x�� ������ Ű�� �� �ֱ� ������ �׻� �����ϴ�.
*/
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int x, y; cin >> x >> y;
		if (x >= y) cout << "YES\n";
		else {
			if (x == 2 && y == 3) cout << "YES\n";
			else if (x >= 4) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}