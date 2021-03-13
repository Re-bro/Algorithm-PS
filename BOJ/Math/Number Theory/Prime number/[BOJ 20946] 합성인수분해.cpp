/*
	[BOJ 20946] 합성인수분해
	Algorithm : Math / Number Theory / Prime number
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll n; cin >> n;
	vector<ll> ans;
	for (ll i = 2; i*i <= n; i++) {
		while (n > 1) {
			if (n%i == 0) {
				ans.push_back(i);
				n /= i;
			}
			else break;
		}
	}
	if (n > 1) ans.push_back(n);
	if (ans.size() < 2) cout << -1;
	else {
		if (sz(ans) % 2) {
			ans[sz(ans) - 2] *= ans.back();
			ans.pop_back();
		}
		for (int i = 0; i < sz(ans); i += 2) cout << ans[i] * ans[i + 1] << ' ';
	}
}