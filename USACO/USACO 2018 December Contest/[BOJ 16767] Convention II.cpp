/*
	[BOJ 16767] Convention II
	Algorithm : Priority queue
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<tuple<int, int, int>> v;
	for (int i = 1; i <= n; i++) {
		ll a, t; cin >> a >> t;
		v.push_back(make_tuple(a, i, t));
	}
	sort(all(v));
	priority_queue<tuple<int, int, int>>pq;
	int s = 1;
	auto[a, i, t] = v[0];
	ll last = a;
	ll ans = 0;
	pq.push(make_tuple(-i, a, t));
	while (!pq.empty()) {
		auto[i, a, t] = pq.top(); pq.pop();
		ans = max(ans, last - a);
		last += t;
		while (s < n) {
			auto[q, w, e] = v[s];
			if (q <= last) {
				pq.push({ -w, q, e });
				s++;
			}
			else {
				if (pq.empty()) {
					last = q;
					pq.push({ -w, q, e });
					s++;
				}
				break;
			}
		}
	}
	cout << ans;
}