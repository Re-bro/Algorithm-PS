#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)1e9;
const double PI = acos(-1);

ll tr[5050][5050];
int n, m, q;
void update(int x, int y, ll val) {
	while (x <=n) {
		int ty = y;
		while (ty <=m) {
			tr[x][ty] += val;
			ty += (ty & -ty);
		}
		x += (x & -x);
	}
}
ll sum(int x, int y) {
	ll ans = 0;
	while (x > 0) {
		int ty = y;
		while (ty > 0) {
			ans += tr[x][ty];
			ty -= (ty & -ty);
		}
		x -= (x & -x);
	}
	return ans;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> q;
	while (q--) {
		int k; cin >> k;
		if (k == 1) {
			int x1, y1, x2, y2; ll d;
			cin >> x1 >> y1 >> x2 >> y2 >> d;
			update(x1, y1, d);
			update(x2 + 1, y1, -d);
			update(x1, y2 + 1, -d);
			update(x2 + 1, y2 + 1, d);
		}
		else {
			int x, y; cin >> x >> y;
			cout << sum(x, y) << '\n';
		}
	}
}