/* [CF 1461A] String Generation
	Algorithm : Ad-hoc 

	�Ӹ������ �̷��� �ʱ� ���ؼ��� abc�� ��� ����س����� �ȴ�.
*/
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			if (i % 3 == 1) cout << 'a';
			else if (i % 3 == 2) cout << 'b';
			else cout << 'c';
		}
		cout << '\n';
	}
}