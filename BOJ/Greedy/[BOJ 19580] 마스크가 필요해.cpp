/* [BOJ 19580] ����ũ�� �ʿ���
	Algorithm : Greedy / Sorting
	
	������� R�� ���� �������, R�� ������ L�� ū ������� �����Ѵ�. 
	�׷��� �տ������� �� ����� �ڽ��� �� �� �ִ� ���� ���� ������ ����ũ�� �����ϴ°� �����̴�. 
	(�ڿ� �ٸ� ����� R�� �� ũ�Ƿ� �� ��� ����ũ�� �� �� �����Ƿ�)
	���� ����ũ���� multiset�� �־�ξ�, lower_bound�� �̿��ؼ� ���Ű����� ����ũ�� ������ ��Ī�����ش�.
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

