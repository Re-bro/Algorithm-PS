/*
	[CF 1484B] Restore Modulo
	Algorithm : Implementation / Math
*/
#include<bits/stdc++.h>

using namespace std;
int a[100010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		bool ismono = true;
		for (int i = 2; i < n; i++) {
			if (a[i] - a[i - 1] != a[i + 1] - a[i]) ismono = false;
		}
		if (n == 2 || ismono) {
			cout << 0 << '\n';
			continue;
		}
		bool chk = true;
		int c = -1;
		int m = -1;
		for (int i = 2; i <= n; i++) {
			if (a[i] >= a[i - 1]) {
				if (c == -1) c = a[i] - a[i - 1];
				else if(c != a[i] - a[i-1])	chk = false;
			}
		}
		for (int i = 2; i <= n; i++) {
			if (a[i] < a[i - 1]) {
				m = max(m, c - a[i] + a[i - 1]);
			}
		}
		if (a[1] >= m) chk = false;
		if (!chk) {
			cout << -1 << '\n';
			continue;
		}
		for (int i = 2; i <= n; i++) {
			if (a[i] != (a[i - 1] + c) % m) chk = false;
		}
		if (!chk) cout << -1 << '\n';
		else cout << m << ' ' << c << '\n';
	}
}