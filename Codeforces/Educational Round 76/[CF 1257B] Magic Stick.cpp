/* [CF 1257B] Magic Stick
	Algorithm : math

	x가 y보다 크거나 같으면 항상 -1씩 줄여나가면 y를 만들 수 있다.
	x가 y보다 작은 경우 중에서는, x = 2이고 y = 3인 경우에 가능하다.
	또 x가 4이상인 경우에는 x를 무한히 키울 수 있기 때문에 항상 가능하다.
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