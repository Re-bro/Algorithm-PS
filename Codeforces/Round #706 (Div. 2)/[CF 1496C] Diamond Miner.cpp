/*
	[CF 1496C] Diamond Miner
	Algorithm : Greedy / Math
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<ll>X, Y;
		for (int i = 1; i <= 2*n; i++) {
			ll x, y; cin >> x >> y;
			if (x == 0) Y.push_back(abs(y));
			else X.push_back(abs(x));
		}
		sort(all(X)); sort(all(Y));
		double ans = 0;
		for (int i = 0; i < n; i++) {
			ans += sqrt(X[i] * X[i] + Y[i] * Y[i]);
		}
		cout << fixed;
		cout.precision(13);
		cout << ans << '\n';
	}
}