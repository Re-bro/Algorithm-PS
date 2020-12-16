/* [CF 1462A] Favorite Sequence
	Algorithm : Implementation
*/
#include<bits/stdc++.h>
using namespace std;

int A[301];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> A[i];
		for (int i = 1; i <= n / 2; i++) cout << A[i] << ' ' << A[n - i + 1] << ' ';
		if (n % 2) cout << A[(n + 1) / 2];
		cout << '\n';
	}
}