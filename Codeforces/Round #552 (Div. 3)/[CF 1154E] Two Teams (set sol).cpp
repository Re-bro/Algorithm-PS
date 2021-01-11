/* [CF 1154E] Two Teams (Set solution)
	Algorithm : Implementation
*/

#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
int ans[200001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	set<int> s;
	priority_queue<pii> pq;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		s.insert(i);
		pq.push({ a, i });
	}
	int turn = 1;
	while (!pq.empty()) {
		pii p = pq.top(); pq.pop();
		auto it = s.lower_bound(p.second);
		if (it == s.end() || *it != p.second) continue;
		ans[p.second] = turn;
		s.erase(it);
		for (int i = 1; i <= k; i++) {
			auto left = s.lower_bound(p.second);
			if (left == s.begin()) break;
			left--;
			ans[*left] = turn;
			s.erase(left);
		}
		for (int i = 1; i <= k; i++) {
			auto right = s.lower_bound(p.second);
			if (right == s.end()) break;
			ans[*right] = turn;
			s.erase(right);
		}
		if (turn == 1) turn = 2;
		else turn = 1;
	}
	for (int i = 1; i <= n; i++) cout << ans[i];
}