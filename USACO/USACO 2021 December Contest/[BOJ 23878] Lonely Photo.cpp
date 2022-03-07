#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	string s; cin >> s;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll l = 0, r = 0;
		if (i > 0 && s[i] != s[i - 1]) {
			l++;
			for (int j = i - 2; j >= 0; j--) {
				if (s[j] == s[i]) break;
				l++;
			}
		}
		if (i < n - 1 && s[i] != s[i + 1]) {
			r++;
			for (int j = i + 2; j < n; j++) {
				if (s[j] == s[i]) break;
				r++;
			}
		}
		ans += l * r + max(l - 1, 0LL) + max(r - 1, 0LL);
	}
	cout << ans;
}