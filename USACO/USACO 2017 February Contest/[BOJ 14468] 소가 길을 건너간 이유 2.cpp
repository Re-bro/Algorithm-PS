/*
	[BOJ 14468] 소가 길을 건너간 이유 2
	Algorithm : Implementation
*/
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		vector<int> chk(26);
		for (int j = i + 1; j < s.size(); j++) {
			if (s[j] == s[i]) {
				for (int k = 0; k < 26; k++) {
					if (chk[k] == 1) ans++;
				}
				break;
			}
			chk[s[j] - 'A']++;
		}
	}
	cout << ans / 2;
}