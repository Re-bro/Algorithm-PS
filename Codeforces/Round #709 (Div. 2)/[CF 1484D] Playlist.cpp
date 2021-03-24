/*
	[CF 1484D] Playlist
	Algorithm : Set / implementation
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;
using pii = pair<int, int>;

int a[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		set<int> alive;
		set<pii> die;
		for (int i = 1; i <= n; i++) cin >> a[i], alive.insert(i);
		alive.insert(n + 1);
		for (int i = 1; i < n; i++) {
			if (gcd(a[i], a[i + 1]) == 1) die.insert({ i, i + 1 });
		}
		if (gcd(a[n], a[1]) == 1) die.insert({ n , 1 });
		vector<int> ans;
		while (!die.empty()) {
			set<pii> tmp;
			for (auto[i, j] : die) {
				if (alive.find(i) == alive.end() || alive.find(j) == alive.end()) continue;
				int k = *alive.lower_bound(j+1);
				if (k == n + 1) k = *alive.begin();
				
				//i -> j -> k & erase j
				alive.erase(j);
				ans.push_back(j);
				if (die.find({ j, k }) != die.end()) die.erase({ j, k });
				if (tmp.find({ j, k }) != tmp.end()) tmp.erase({ j, k });

				if (i != j && gcd(a[i], a[k]) == 1) tmp.insert({ i, k });
				if (die.empty()) break;
			}
			die = tmp;
		}
		cout << sz(ans) << ' ';
		for (int i : ans) cout << i << ' ';
		cout << '\n';
	}
}