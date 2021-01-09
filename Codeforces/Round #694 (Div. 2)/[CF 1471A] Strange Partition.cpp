/* [CF 1471A] Strange Partition
	Algorithm : math / Implementation

	�ִ��� ���� ������ �ѹ��� ���� ���� ������ �迭���� ���� �����ִ� ����̰�, 
	�ּ��� ���� ������ n-1�� ������, �� �迭�� ���Ұ� 1���� ������ ���̴�. 
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		ll n, x; cin >> n >> x;
		ll mi = 0, mx = 0;
		for (int i = 1; i <= n; i++) {
			ll a; cin >> a;
			mi += a;
			mx += (a + x - 1) / x;
		}
		cout << (mi + x - 1) / x << ' ' << mx << '\n';
	}
}