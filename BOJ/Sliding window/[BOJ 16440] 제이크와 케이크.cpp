/*
	[BOJ 16440] 力捞农客 纳捞农
	Algorithm : Sliding window
*/

#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	string s; cin >> s;
	int scnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 's') scnt++;
		if (i == n / 2 - 1 && scnt == n / 4) {
			cout << 1 << '\n' << i+1;
			return 0;
		}
		if (i < n / 2) continue;
		if (s[i - n / 2] == 's') scnt--;
		if (scnt == n / 4) {
			cout <<2<<'\n'<< i+1 - n / 2 << ' ' << i+1;
			return 0;
		}
	}
}

