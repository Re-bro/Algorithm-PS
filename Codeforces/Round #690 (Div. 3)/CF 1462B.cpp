/* [CF 1462B] Last Year's Substring
	Algorithm : Implementation

	하나 이하의 구간을 제거해서 "2020"을 만들 수 있는지에 대한 문제이다. 
	n이 최대 200이므로 4개를 남기고 자르는 모든 경우를 비교해보면 된다.
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		string s; cin >> s;
		bool chk = false;
		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			int j = sz(s) - (4 - i) - 1;
			string tmp = "";
			for (int k = 0; k < sz(s); k++) {
				if (k >= i && k <= j) continue;
				tmp += s[k];
			}
			if (tmp == "2020") chk = true;

		}
		if (chk) cout << "YES\n";
		else cout << "NO\n";
	}
}