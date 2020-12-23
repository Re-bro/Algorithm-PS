/* [BOJ 18324] Race
	Algorithm : Binary Search / Greedy / Math

	시간을 최소로 하여 K이상만큼 뛰기 위해서는 속도를 최대로 높일 수 있을만큼 높였다가 내려 와야 한다.
											 _
	    _ _ _                          ／   ＼
	／	       ＼     보다     ／            ＼   가 항상 더 많이 이동하기 때문이다. 
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll K, N; cin >> K >> N;
	for (int i = 1; i <= N; i++) {
		ll X; cin >> X;
		ll s = 1;
		ll e = 100000;
		ll ans = 1e18;
		while (s <= e) {
			ll mid = (s + e) / 2;
			ll val = mid * (mid + 1) / 2;
			if (mid <= X && val >= K) {
				ans = min(ans, mid);
				e = mid - 1;
			}
			else {
				val += (mid - 1) * mid / 2 - (X - 1) * X / 2;
				if (val >= K) {
					ans = min(ans, 2 * mid - X);
					e = mid - 1;
				}
				else {
					ans = min(ans, 2 * mid - X + (K - val) / mid + ((K - val) % mid != 0));
					s = mid + 1;
				}
			}
		}
		cout << ans << '\n';
	}
}