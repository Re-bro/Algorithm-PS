/*
	[CF 1494B] Berland Crossword
	Algorithm : math / greedy
*/
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, u, r, d, l; cin >> n >> u >> r >> d >> l;
		int ud = 0, lr = 0;
		if (u == n) lr++;
		if (d == n) lr++;
		if (l == n) ud++;
		if (r == n) ud++;
		if (ud > u || ud > d || lr > r || lr > l) cout << "NO\n";
		else {
			ud = 0; lr = 0;
			ud = max(l - n + 2, 0) + max(r - n + 2, 0);
			lr = max(u - n + 2, 0) + max(d - n + 2, 0);
			if (ud > (u + d) || lr > (l + r)) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}