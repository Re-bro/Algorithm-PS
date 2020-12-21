/* [CF 1463B] Find The Array
	Algorithm : Constructive

	�� ���Һ��� �ڽ��� ���� �����鼭 �ִ��� 2�� �������� �Ҵ����ָ� �ȴ�.
	�׷��� ai - bi�� �ϰ� �Ǹ� ai�� MSB�� ������ �ǰ�, �� ���� 
	ai - bi���� ũ�� ������ ����3�� �����ϰ� �ȴ�. 
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll A[51];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		ll total = 0;
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			for (int j = 30; j >= 0; j--) {
				if ((1LL << j) & A[i]) {
					cout << (1 << j) << ' ';
					break;
				}
			}
		}
		cout << '\n';
	}
}