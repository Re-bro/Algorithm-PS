#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	string ans = "";
	while (T--) {
		int n, m; cin >> n >> m;
		cin.get();
		vector<vector<int>> v(m + 1, vector<int>());
		for (int i = 1; i <= m; i++) {
			string s; getline(cin, s);
			int now = 0;
			for (int j = 0; j < s.size(); j++) {
				if (s[j] == ' ') {
					v[i].push_back(now);
					now = 0;
				}
				else now = now * 10 + s[j] - '0';
			}
			v[i].push_back(now);
		}
		bool flag = false;
		for (int i = 0; i < (1 << n); i++) {
			bool chk = true;
			vector<int> cnt(m + 1);
			for (int j = 1; j <= m; j++) {
				for (auto k : v[j]) {
					if ((1 << (k - 1)) & i) {
						cnt[j]++;
						if (cnt[j] == v[j].size()) {
							chk = false;
							break;
						}
					}
				}
				if (!chk) break;
			}
			for (int j = 1; j <= m; j++) {
				if (cnt[j] == 0) chk = false;
			}
			if (chk) {
				flag = true;
				break;
			}
		}
		if (flag) ans += "Y";
		else ans += "N";
	}
	cout << ans;
}