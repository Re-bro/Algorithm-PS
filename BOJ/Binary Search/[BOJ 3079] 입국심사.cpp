/* [BOJ 3079] 입국심사
	Algorithm : Binary Search
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll t[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll n, m; cin >> n >> m;
	ll s = 0;
	ll e = (ll)1e15;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	ll ans = 1e18;
	while (s <= e) {
		ll mid = (s + e) / 2;
		ll tmp = 0;
		for (int i = 1; i <= n; i++) {
			tmp += mid / t[i];
		}
		if (tmp >= m) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else s = mid + 1;
	}
	cout << ans;
}