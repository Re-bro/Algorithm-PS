/*
	[CF 1493B] Planet Lapituletti
	Algorithm : Brute-force / Implementation
*/
#include<bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int h, m; cin >> h >> m;
		string s; cin >> s;
		int nh, nm;
		nh = (s[0] - '0') * 10 + s[1] - '0';
		nm = (s[3] - '0') * 10 + s[4] - '0';
		for (int i = 0; ; i++) {
			int x = (nh + (nm + i) / m) % h;
			int y = (nm + i) % m;
			if (x == 0 && y == 0) {
				cout << "00:00\n";
				break;
			}
			vector<int> v(4);
			v[0] = y % 10;
			v[1] = y / 10;
			v[2] = x % 10;
			v[3] = x / 10;
			bool chk = false;
			for (int j = 0; j < 4; j++) {
				if (v[j] == 2) v[j] = 5;
				else if (v[j] == 5) v[j] = 2;
				else if (v[j] != 0 && v[j] != 1 && v[j] != 8) chk = true;
			}
			if (chk) continue;
			if (v[0] * 10 + v[1] < h && v[2] * 10 + v[3] < m) {
				cout << x / 10 << x % 10 << ':' << y / 10 << y % 10 << '\n';
				break;
			}
		}
	}
}