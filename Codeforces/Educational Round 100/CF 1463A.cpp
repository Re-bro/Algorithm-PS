/* [CF 1463A] Dungeon
	Algorithm : Math
	
	enhanced가 들어오는 경우에 모두 0이 되기 위해서는 9의 배수여야 한다. 
	그리고, enhanced마다 모두 1씩 감소시키므로, a,b,c가 각각
	enhanced의 횟수 이상은 되어야 한다.
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