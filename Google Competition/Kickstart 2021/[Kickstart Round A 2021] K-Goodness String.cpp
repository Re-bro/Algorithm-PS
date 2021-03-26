/*
	[Kickstart Round A 2021] K-Goodness String
	Algorithm : Implementation
*/
#include<bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		int cnt = 0;
		for (int i = 1; i <= n / 2; i++) {
			if (s[i - 1] != s[n - i]) cnt++;
		}
		cout << "Case #" << t << ": " << abs(cnt - k) << '\n';
	}
}