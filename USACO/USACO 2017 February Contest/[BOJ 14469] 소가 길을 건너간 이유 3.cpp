/*
	[BOJ 14469] 소가 길을 건너간 이유 3
	Algorithm : Greedy / Sorting
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
		int a, b; cin >> a >> b;
		v.pb({ a, b });
	}
	sort(all(v));
	int last = 0;
	for (int i = 0; i < sz(v); i++) {
		if (last >= v[i].first) {
			last += v[i].second;
		}
		else {
			last = v[i].first + v[i].second;
		}
	}
	cout << last;
}