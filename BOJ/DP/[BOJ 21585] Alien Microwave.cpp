/*
	[BOJ 21585] Alien Microwave
	Algorithm : DP / Prefix sum
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

using namespace std;

ll t[11];
ll pre[11];
ll suf[11][101];
int main(void) {
	int n; cin >> n;
	pre[0] = 1;
	for (int i = 1; i <= n; i++) cin >> t[i], pre[i] = pre[i - 1] * t[i];
	ll ans = 0;
	for (int i = 0; i <= 100; i++) suf[n][i] = 1;
	for (int i = n; i > 1; i--) {
		for (int j = 0; j < t[i]; j++) {
			ll d10 = j / 10;
			ll d1 = j % 10;
			if ((d1 >= t[i] % 10) || (d10 >= t[i] % 10)) {
				for (int k = 0; k < t[i - 1]; k++) {
					if (k > 0 && (k % 10 >= t[i] / 10)) 	ans += pre[i - 2] * suf[i][j];
					else suf[i - 1][k] += suf[i][j];
				}
			}
			else {
				for (int k = 0; k < t[i - 1]; k++) {
					if (k > 0 && (k % 10 > t[i] / 10)) ans += pre[i - 2] * suf[i][j];
					else suf[i - 1][k] += suf[i][j];
				}
			}
		}
	}
	cout << ans;
}