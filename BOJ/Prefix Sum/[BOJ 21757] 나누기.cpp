/*
	[BOJ 21757] ³ª´©±â
	Algorithm : DP / Prefix Sum
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[101010];
int pre[101010];
int suf[101010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i], a[i] += a[i - 1];
	}
	if (a[n] % 4) return cout << 0, 0;
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1];
		suf[n + 1 - i] = suf[n + 2 - i];
		if (a[i] == a[n] / 4) pre[i]++;
		if (a[n - i] == a[n] * 3 / 4) suf[n + 1 - i]++;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[n] / 2) {
			ans += 1LL * pre[i - 1] * suf[i + 2];
		}
	}
	cout << ans;
}