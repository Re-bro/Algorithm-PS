/*
	[CF 1504A] Deja Vu
	Algorithm : Implementation / Constructive
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		string s1 = 'a' + s;
		string s2 = s + 'a';
		bool chk = true;
		for (int i = 0; i < sz(s1); i++) {
			if (s1[i] != s1[sz(s1) - 1 - i]) chk = false;
		}
		if (!chk) {
			cout << "YES\n";
			cout << s1 << '\n';
			continue;
		}
		for (int i = 0; i < sz(s2); i++) {
			if (s2[i] != s2[sz(s2) - 1 - i]) chk = false;
		}
		if (!chk) {
			cout << "YES\n";
			cout << s2 << '\n';
			continue;
		}
		cout << "NO\n";
	}
}