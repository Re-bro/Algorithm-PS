/*
	[CF 1496B] Max and Mex
	Algorithm : Implementation / Math
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		set<int> s;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			s.insert(a);
		}
		if (k == 0) {
			cout << sz(s) << '\n';
			continue;
		}
		int mx = *s.rbegin();
		int mex = 0;
		for (auto a : s) {
			if (a == mex) mex++;
		}
		if (mex > mx) cout << sz(s) + k << '\n';
		else {
			s.insert((mex + mx + 1) / 2);
			cout << sz(s) << '\n';
		}
	}
}