#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		mp[a]++;
	}
	ll ans = 0;
	for (auto [a, b] : mp) {
		ans += 1LL * b * (n - b);
	}
	cout << ans / 2;
}