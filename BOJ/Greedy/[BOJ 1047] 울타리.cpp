/*
	[BOJ 1047] ¿ïÅ¸¸®
	Algorithm : Brute-force / Greedy
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

struct tree {
	int x, y, l;
};
vector<tree> v;
int n;
int ans;
set<ll> s;
int len(ll bit) {
	int l = MAX, r = 0, u = 0, d = MAX;
	for (int i = 0; i < n; i++) {
		if (((1LL << i) & bit) == 0) {
			l = min(l, v[i].x);
			r = max(r, v[i].x);
			u = max(u, v[i].y);
			d = min(d, v[i].y);
		}
	}
	return 2 * (r - l + u - d);
}
void sol(ll bit, int cnt, int fence) {
	if (s.find(bit) != s.end()) return;
	s.insert(bit);
	if (fence >= len(bit)) {
		ans = min(ans, cnt);
		return;
	}
	if (cnt >= ans) return;
	int l, r, u, d, mx;
	tree L, R, U, D, MX;
	L.x = MAX;
	R.x = 0;
	U.y = 0;
	D.y = MAX;
	MX.l = 0;
	for (int i = 0; i < n; i++) {
		if ((1LL << i) & bit) continue;
		if (L.x > v[i].x || (L.x == v[i].x && L.l < v[i].l)) {
			L = v[i];
			l = i;
		}
		if (R.x < v[i].x || (R.x == v[i].x && R.l < v[i].l)) {
			R = v[i];
			r = i;
		}
		if (U.y < v[i].y || (U.y == v[i].y && U.l < v[i].l)){
			U = v[i];
			u = i;
		}
		if (D.y > v[i].y || (D.y == v[i].y && D.l < v[i].l)) {
			D = v[i];
			d = i;
		}
		if (MX.l < v[i].l) {
			MX = v[i];
			mx = i;
		}
	}
	sol(bit | (1LL << l), cnt + 1, L.l + fence);
	sol(bit | (1LL << r), cnt + 1, R.l + fence);
	sol(bit | (1LL << u), cnt + 1, U.l + fence);
	sol(bit | (1LL << d), cnt + 1, D.l + fence);
	sol(bit | (1LL << mx), cnt + 1, MX.l + fence);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n;
	ans = MAX;
	for (int i = 1; i <= n; i++) {
		int x, y, l; cin >> x >> y >> l;
		v.pb({ x, y, l });
	}
	sol(0, 0, 0);
	cout << ans;
}