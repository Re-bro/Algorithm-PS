/* [CF 1473C] No More Inversions
	Algorithm : constructive

*/
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		if (n == k) for (int i = 1; i <= n; i++) cout << i << ' ';
		else {
			for (int i = 1; i <= 2 * k - 1 - n; i++) cout << i << ' ';
			for (int i = k; i > 2 * k - 1 - n; i--) cout << i << ' ';
		}
		cout << '\n';
	}
}