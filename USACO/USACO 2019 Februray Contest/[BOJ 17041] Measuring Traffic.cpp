/*
	[BOJ 17041] Measuring Traffic
	Algorithm : Implementation
*/

#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<tuple<string, int, int>> v;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		int a, b; cin >> a >> b;
		v.push_back(make_tuple(s, a, b));
	}
	int mi = 1000000, mx = -1;
	int mi2 = 1000000, mx2 = -1;
	for (int i = 0; i <= 100000; i++) {
		int l = i;
		int r = i;
		for (auto[s, a, b] : v) {
			if (s == "on") {
				l += a;
				r += b;
			}
			else if (s == "off") {
				l = max(0, l - b);
				r -= a;
			}
			else {
				l = max(l, a);
				r = min(r, b);
			}
			if (l > r) break;
		}
		if (l <= r) {
			mi = min(mi, i);
			mx = max(mx, i);
			mi2 = min(l, mi2);
			mx2 = max(r, mx2);
		}
	}
	cout << mi << ' ' << mx << '\n';
	cout << mi2 << ' ' << mx2;
}