/* [BOJ 20300] 서강근육맨
	Algorithm : Binary search, Greedy

	풀이 : https://wogud6792.tistory.com/78
*/


#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll t[10001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> t[i];
	sort(t + 1, t + 1 + N);
	ll s = 0;
	ll e = (ll)2 * 1e18;
	ll ans = (ll)2 * 1e18;
	while (s <= e) {
		ll mid = (s + e) / 2;
		int l = 1;
		int r = N;
		int tmp = 0;
		if (t[N] > mid) {
			s = mid + 1;
			continue;
		}
		while (l <= r) {
			if (l == r) {
				tmp++;
				break;
			}
			if (t[l] + t[r] > mid) {
				tmp++;
				r--;
			}
			else {
				l++;
				r--;
				tmp++;
			}
		}
		if (tmp > (N + 1) / 2) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
			ans = min(mid, ans);
		}
	}
	cout << ans;
}