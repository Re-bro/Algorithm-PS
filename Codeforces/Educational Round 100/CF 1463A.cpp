/* [CF 1463A] Dungeon
	Algorithm : Math
	
	enhanced�� ������ ��쿡 ��� 0�� �Ǳ� ���ؼ��� 9�� ������� �Ѵ�. 
	�׸���, enhanced���� ��� 1�� ���ҽ�Ű�Ƿ�, a,b,c�� ����
	enhanced�� Ƚ�� �̻��� �Ǿ�� �Ѵ�.
*/
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int a, b, c; cin >> a >> b >> c;
		int k = a + b + c;
		int mi = k / 9;
		if (a < mi || b < mi || c < mi) cout << "NO\n";
		else if (k % 9 == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}