/* [BOJ 19580] 마스크가 필요해
	Algorithm : Greedy / Sorting
	
	사람들을 R이 작은 순서대로, R이 같으면 L이 큰 순서대로 정렬한다. 
	그러면 앞에서부터 각 사람이 자신이 살 수 있는 가장 작은 가격의 마스크를 구매하는게 최적이다. 
	(뒤에 다른 사람은 R이 더 크므로 더 비싼 마스크를 살 수 있으므로)
	따라서 마스크들을 multiset에 넣어두어, lower_bound를 이용해서 구매가능한 마스크가 있으면 매칭시켜준다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
int n, m;
bool cmp(pll a, pll b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second < b.second;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	vector<pll> v;
	for (int i = 1; i <= n; i++) {
		ll l, r; cin >> l >> r;
		v.push_back({ l, r });
	}
	multiset<pll> mask;
	for (int i = 1; i <= m; i++) {
		ll p, x; cin >> p >> x;
		mask.insert({ p, x });
	}
	sort(all(v), cmp);
	int ans = 0;
	for (auto[l, r] : v) {
		auto it = mask.lower_bound({ l, 0 });
		if (it == mask.end()) continue;
		auto[p, x] = *it;
		if (x > 0 && p <= r) {
			ans++;
			mask.erase(it);
			if (x > 1) mask.insert({ p, x - 1 });
		}
	}
	cout << ans;
}

