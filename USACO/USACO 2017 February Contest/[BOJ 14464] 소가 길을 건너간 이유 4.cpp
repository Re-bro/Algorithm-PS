/*
	[BOJ 14464] 소가 길을 건너간 이유 4
	Algorithm : Greedy / Sorting
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using pii = pair<int, int>;
int t[20202];

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int c, n; cin >> c >> n;
	for (int i = 1; i <= c; i++) {
		cin >> t[i];
	}
	sort(t + 1, t + 1 + c);
	vector<pii> v;
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		v.pb({ b, a });
	}
	sort(all(v));
	int s = 1;
	multiset<int> st;
	int ans = 0;
	for (auto [b, a] : v) {
		while (t[s] <= b && s <= c) {
			st.insert(t[s]);
			s++;
		}
		if (st.empty()) continue;
		auto it = st.lower_bound(a);
		if (it != st.end()) {
			ans++;
			st.erase(it);
		}
	}
	cout << ans;
}