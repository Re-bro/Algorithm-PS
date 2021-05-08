/*
	[BOJ 16764] Cowpatibility
	Algorithm : map / inclusion and exclusion
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
map<vector<int>, int> mp;
vector<vector<int>> v;
void make(int idx, int bit, int num) {
	if (idx == 5) {
		if (bit != 0) {
			vector<int> tmp;
			for (int i = 0; i < 5; i++) {
				if ((1 << i) & bit) tmp.pb(v[num][i]);
			}
			mp[tmp]++;
		}
		return;
	}
	make(idx + 1, bit | (1 << idx), num);
	make(idx + 1, bit, num);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	v.assign(n, vector<int>(5));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) cin >> v[i][j];
		sort(all(v[i]));
		make(0, 0, i);
	}
	ll ans = 0;
	for (auto[a, b] : mp) {
		if (sz(a) % 2) ans += 1LL * b*(b - 1) / 2;
		else ans -= 1LL * b*(b - 1) / 2;
	}

	cout << 1LL * n*(n - 1) / 2 - ans;
}