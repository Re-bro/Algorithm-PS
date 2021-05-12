/*
	[BOJ 15589] Lifeguards (Silver)
	Algorithm : Sweeping
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
const int MAX = (int)2e9;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<pii> v;
	for (int i = 1; i <= n; i++) {
		int l, r; cin >> l >> r;
		v.pb({ l, r });
	}
	v.pb({ MAX, MAX });
	sort(all(v));
	int total = 0;
	int mi = MAX;
	int last = -1;
	for (int i = 0; i < n; i++) {
		last = max(last, v[i].fi);
		mi = min(mi, max(min(v[i].se, v[i + 1].fi) - last, 0));
		total += max(0, v[i].se - last);
		last = max(last, v[i].se);
	}
	cout << total - mi;

}