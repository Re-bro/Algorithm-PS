/*
	[CF 1494A] ABC string
	Algorithm : Brute-force / Bitmask
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		bool chk = false;
		for (int i = 0; i < 8; i++) {
			int cnt = 0;
			for (int j = 0; j < sz(s); j++) {
				if ((1<<(s[j] - 'A')) & i) cnt++;
				else cnt--;
				if (cnt < 0) break;
			}
			if (cnt == 0) {
				chk = true;
				break;
			}
		}
		cout << (chk ? "YES\n" : "NO\n");
	}
}