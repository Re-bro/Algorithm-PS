#include<bits/stdc++.h>
using namespace std;

int p[101010], t[101010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) cin >> t[i], p[i] -= t[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i - 1] * p[i] <= 0) ans += abs(p[i]);
		else ans += max(0, abs(p[i]) - abs(p[i - 1]));
	}
	cout << ans;
}