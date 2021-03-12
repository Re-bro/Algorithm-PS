/*
	[CF 1493C] K-beautiful String
	Algorithm : Brute-force / String / Greedy
*/
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		vector<int> cnt(26);
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
		}
		bool can = true;
		for (int i = 0; i < 26; i++) {
			if ((cnt[i] % k) != 0) can = false;
		}
		if (can) {
			cout << s << '\n';
			continue;
		}
		if (n % k != 0) cout << -1 << '\n';
		else if (k == 1) cout << s << '\n';
		else {
			cnt.assign(26, 0);
			int idx = -1;
			int val = -1;
			for (int i = 0; i < n; i++) {
				vector<int> tmp(26);
				for (int j = s[i] - 'a' + 1; j < 26; j++) {
					tmp[j] = 1;
					int r = n - i - 1;
					for (int q = 0; q < 26; q++) {
						int w = (cnt[q] + tmp[q]) % k;
						if (w > 0) r -= (k - w);
					}
					if (r >= 0 && r % k == 0) {
						idx = i;
						val = j;
						break;
					}
					tmp[j] = 0;
				}
				cnt[s[i] - 'a']++;
			}
			if (idx == -1) {
				cout << -1 << '\n';
			}
			else {
				cnt.assign(26, 0);
				for (int i = 0; i < idx; i++) {
					cnt[s[i] - 'a']++;
				}
				s[idx] = 'a' + val;
				cnt[val]++;
				for (int i = n - 1; i > idx; i--) {
					bool chk = false;
					for (int j = 25; j >= 0; j--) {
						if (cnt[j] % k != 0) {
							s[i] = 'a' + j;
							cnt[j]++;
							chk = true;
							break;
						}
					}
					if (!chk) s[i] = 'a';
				}
				cout << s << '\n';
			}
		}
	}
}