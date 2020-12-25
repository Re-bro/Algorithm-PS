/* [BOJ 18265] MooBuzz
	Algorithm : Binary Search

	k까지 셀 때, 숫자가 나오는 개수는 3의 배수와 5의 배수를 제외한 개수이다. 
	즉, k - k/3 - k/5 + k/15가 숫자가 나오는 개수이다. 
	따라서 이 값이 N보다 크다면 k를 줄여줘야 하고, N보다 작다면 k를 키워줘야 한다.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll N; cin >> N;
	ll s = 1;
	ll e = (ll)1e18;
	ll ans = (ll)1e18;
	while (s <= e) {
		ll mid = (s + e) / 2;
		ll k = mid - mid / 3 - mid / 5 + mid / 15;
		if (k >= N) {
			if(k == N) ans = min(ans, mid);
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << ans;
}