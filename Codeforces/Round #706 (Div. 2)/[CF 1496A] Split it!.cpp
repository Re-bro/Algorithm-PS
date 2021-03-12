/*
	[CF 1496A] Split it!
	Algorithm : Greedy
*/

#include<bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		int cnt = 0;
		for (int i = 0; i < n / 2; i++) {
			if (s[i] == s[n - 1 - i]) cnt++;
			else break;
		}
		cout <<(cnt >=k && 2*k+1 <= n ? "YES\n" : "NO\n");
	}
}