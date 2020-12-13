/* [CF 1461A] String Generation
	Algorithm : Ad-hoc 

	팰린드롬을 이루지 않기 위해서는 abc를 계속 출력해나가면 된다.
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