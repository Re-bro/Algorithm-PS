/* [CF 1462F] The Treasure of The Segments
	Algorithm : ÁÂÇ¥¾ÐÃà / Segment tree
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MAX = (int)2e9;
int tr[1600001];
void init(int x, int s, int e) {
	if (s == e) tr[x] = 0;
	else {
		init(x * 2, s, (s + e) / 2);
		init(x * 2 + 1, (s + e) / 2 + 1, e);
	}
}
void update(int x, int s, int e, int i, int val) {
	if (i > e || i < s) return;
	tr[x] += val;
	if (s != e) {
		update(x * 2, s, (s + e) / 2, i, val);
		update(x * 2 + 1, (s + e) / 2 + 1, e, i, val);
	}
}
int sum(int x, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tr[x];
	else return sum(x * 2, s, (s + e) / 2, l, r) + sum(x * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<pii> v(n + 1);
		vector<int> val;
		map<int, int> mp;
		for (int i = 1; i <= n; i++) {
			cin >> v[i].first >> v[i].second;
			val.push_back(v[i].first);
			val.push_back(v[i].second);
		}
		sort(all(val));
		val.erase(unique(all(val)), val.end());
		for (int i = 0; i < sz(val); i++) {
			mp[val[i]] = i + 1;
		}
		for (int i = 1; i <= n; i++) {
			v[i].first = mp[v[i].first];
			v[i].second = mp[v[i].second];
		}
		sort(v.begin() + 1, v.end());
		int ans = MAX;
		int N = sz(val);
		fill(tr, tr + 4 * N + 1, 0);
		for (int i = 1; i <= n; i++) {
			update(1, 1, N, v[i].first, 1);
		}
		for (int i = 1; i <= n; i++) {
			ans = min(ans, n - sum(1, 1, N, v[i].first, v[i].second));
			update(1, 1, N, v[i].first, -1);
			update(1, 1, N, v[i].second, 1);
		}
		cout << ans << '\n';
	}
}