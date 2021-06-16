/*
	[BOJ 14527] Paired Up
	Algorithm : Greedy / Two-pointer
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;
using pii = pair<int, int>;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<pii> v;
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		v.pb({ y, x });
	}
	sort(all(v));
	int s = 0;
	int e = n - 1;
	int ans = 0;
	while (s <= e) {
		int mi = min(v[s].second, v[e].second);
		ans = max(ans, v[s].first + v[e].first);
		v[s].second -= mi;
		v[e].second = max(v[e].second - mi, 0);
		if (v[s].second == 0) s++;
		if (v[e].second == 0) e--;
	}
	cout << ans;
}