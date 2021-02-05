/* [BOJ 5419] ºÏ¼­Ç³
	Algorithm : Segment Tree / coordinate compression
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int tr[75001];
int n;
bool cmp(pii a, pii b) {
	if (a.second == b.second) return a.first > b.first;
	else return a.second < b.second;
}
void update(int i) {
	while (i <= 75000) {
		tr[i] ++;
		i += (i&-i);
	}
}
int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += tr[i];
		i -= (i&-i);
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		ini(tr, 0);
		cin >> n;
		vector<pii> v;
		vector<int> tmp;
		for (int i = 1; i <= n; i++) {
			int x, y; cin >> x >> y;
			v.push_back({ x, y });
			tmp.push_back(x);
		}
		sort(all(tmp));
		map<int, int> mp;
		for (int i = 0; i < sz(tmp); i++) mp[tmp[i]] = i + 1;
		for (int i = 0; i < n; i++) v[i].first = mp[v[i].first];
		sort(all(v), cmp);
		ll ans = 0;
		for (int i = 0; i < sz(v); i++) {
			ans += sum(75000) - sum(v[i].first - 1);
			update(v[i].first);
		}
		cout << ans << '\n';
	}
}