/*
	[BOJ 15760] Out of Sorts
	Algorithm : Greedy / Sorting
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using pii = pair<int, int>;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(all(v));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, v[i].second - i);
	}
	cout << ans+1;
}