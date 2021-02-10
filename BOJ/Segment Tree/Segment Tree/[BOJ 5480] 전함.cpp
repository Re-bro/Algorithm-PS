/* [BOJ 5480] ภüวิ
	Algorithm : Segment Tree / Offline query / coordinate compression
*/
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
const int MAX = (int)2e9;
const double PI = acos(-1);

struct ship {
	int x1, y1, x2, y2, w;
};
int xtr[1200001];
int ytr[1200001];
int update(int* tr, int x, int s, int e, int i, int val) {
	if (i > e || i < s) return tr[x];
	if (s == e) return tr[x] = val;
	return tr[x] = min(update(tr, x * 2, s, (s + e) / 2, i, val), update(tr, x * 2 + 1, (s + e) / 2 + 1, e, i, val));
}
int qry(int* tr, int x, int s, int e, int l, int r) {
	if (s > r || e < l) return MAX;
	else if (s >= l && e <= r) return tr[x];
	else return min(qry(tr, x * 2, s, (s + e) / 2, l, r), qry(tr, x * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int mp(vector<int>& v, int a) {
	return lower_bound(all(v), a) - v.begin() + 1;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		fill(xtr, xtr + 1200001, MAX);
		fill(ytr, ytr + 1200001, MAX);
		vector<int> X, Y;
		int n, k, l; cin >> n >> k >> l;
		vector<ship> v;
		for (int i = 0; i < k; i++) {
			ship s;
			cin >> s.x1 >> s.y1 >> s.x2 >> s.y2 >> s.w;
			if (s.x1 > s.x2) swap(s.x1, s.x2);
			if (s.y1 > s.y2) swap(s.y1, s.y2);
			X.pb(s.x1); X.pb(s.x2); Y.pb(s.y1); Y.pb(s.y2);
			v.pb(s);
		}
		vector<pii> laser;
		for (int i = 1; i <= l; i++) {
			int a, b; cin >> a >> b;
			laser.pb({ a, b });
			if (b == 0) Y.pb(a);
			else X.pb(a);
		}
		sort(all(X)); sort(all(Y));
		X.erase(unique(all(X)), X.end());
		Y.erase(unique(all(Y)), Y.end());
		int nx = sz(X);
		int ny = sz(Y);
		for (int i = l - 1; i >= 0; i--) {
			if (laser[i].se == 0) {
				update(ytr, 1, 1, ny, mp(Y, laser[i].fi), i + 1);
			}
			else {
				update(xtr, 1, 1, nx, mp(X, laser[i].fi), i + 1);
			}
		}
		vector<int> ans(l + 1);
		for (int i = 0; i < k; i++) {
			int idx = min(qry(xtr, 1, 1, nx, mp(X, v[i].x1), mp(X, v[i].x2)), qry(ytr, 1, 1, ny, mp(Y, v[i].y1), mp(Y, v[i].y2)));
			if (idx != MAX) ans[idx] = max(ans[idx], v[i].w);
		}
		for (int i = 1; i <= l; i++) cout << ans[i] << '\n';
	}
}