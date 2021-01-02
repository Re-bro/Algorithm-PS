/* [CF 1257C] Dominated Subarray
	Algorithm : Greedy / Two pointer
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;

int A[200001];
int main(void) {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> cnt(n + 1);
		int ans = MAX;
		for (int i = 1; i <= n; i++) cin >> A[i];
		int s = 1;
		for (int i = 1; i <= n; i++) {
			cnt[A[i]]++;
			if (cnt[A[i]] == 2) {
				while (A[s] != A[i]) {
					cnt[A[s]]--;
					s++;
				}
				ans = min(ans, i - s + 1);
				cnt[A[s]]--;
				s++;
			}
		}
		if (ans == MAX) cout << -1 << '\n';
		else cout << ans << '\n';
	}
}