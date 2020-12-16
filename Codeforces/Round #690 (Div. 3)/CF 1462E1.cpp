/* [CF 1462E1] Close Tuples (easy version)

*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int A[200001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> cnt(2 * n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			cnt[A[i]]++;
		}
		sort(A + 1, A + 1 + n);
		ll ans = 0;
		for (int i = 1; i <= n - 2; i++) {
			ll k1 = lower_bound(A + 1, A + 1 + n, A[i] + 2) - A;
			k1 += cnt[A[i] + 2] - 1;
			if (k1 - i + 1 >= 2) ans += (k1 - i)*(k1 - i - 1) / 2;
		}
		cout << ans << '\n';
	}
}