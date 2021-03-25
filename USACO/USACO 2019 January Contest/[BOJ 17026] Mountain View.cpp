/*
	[BOJ 17026] Mountain View
	Algorithm : Stack
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define pb push_back
using namespace std;
using pii = pair<int, int>;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<pii> v;
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		v.pb({ x, y });
	}
	sort(all(v));
	stack<pii> s;
	s.push({ -1, -1 });
	for (auto [x, y] : v) {
		auto [px, py] = s.top();
		if (py - (x - px) >= y) continue;
		else {
			while (!s.empty()) {
				auto [px, py] = s.top();
				if (y - (x - px) >= py) s.pop();
				else break;
			}
			s.push({ x, y });
		}
	}
	cout << sz(s);
}