#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);


int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		vector<pii>v;
		for (int i = 1; i <= n; i++) {
			int x, y; cin >> x >> y;
			v.push_back({ x, y });
		}
		bool chk = false;
		for (int i = 0; i < n; i++) {
			bool chk2 = true;
			for (int j = 0; j < n; j++) {
				if (abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) > k) chk2 = false;
			}
			if (chk2) chk = true;
		}
		if (chk) cout << 1 << '\n';
		else cout << -1 << '\n';
	}
}