/* [BOJ 1543] 문서 검색
	Algorithm : Brute-force
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string s, p;
	getline(cin, s);
	getline(cin, p);
	int i = 0;
	int ans = 0;
	while(1) {
		if (i + sz(p) > sz(s)) break;
		bool chk = true;
		for (int j = 0; j < sz(p); j++) {
			if (s[i + j] != p[j]) chk = false;
		}
		if (chk) {
			ans++;
			i += sz(p);
		}
		else i++;
	}
	cout << ans;
}