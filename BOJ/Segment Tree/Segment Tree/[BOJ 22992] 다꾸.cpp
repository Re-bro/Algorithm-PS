/*
	[BOJ 22992] 다꾸
	Algorithm : Segment Tree (금광 세그) , case work
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
const ll MAX = (ll)1e16;
const double PI = acos(-1);
struct seg {
	ll L, R, total, mx, mi, miL, miR;
};
vector<vector<seg>> htr;
vector<vector<seg>> wtr;
int H, W, T;

void update(vector<seg>& tr, int x, int s, int e, int i, ll val) {
	if (i < s || i > e) return;
	if (s == e) {
		tr[x].total += val;
		tr[x].L += val;
		tr[x].R += val;
		tr[x].mx += val;
		tr[x].mi += val;
		tr[x].miL += val;
		tr[x].miR += val;
	}
	else {
		update(tr, x * 2, s, (s + e) / 2, i, val);
		update(tr, x * 2 + 1, (s + e) / 2 + 1, e, i, val);
		tr[x].L = max(tr[x * 2].L, tr[x * 2].total + tr[x * 2 + 1].L);
		tr[x].R = max(tr[x * 2].R + tr[x * 2 + 1].total, tr[x * 2 + 1].R);
		tr[x].total = tr[x * 2].total + tr[x * 2 + 1].total;
		tr[x].mx = max({ tr[x * 2].mx, tr[x * 2 + 1].mx, tr[x * 2].R + tr[x * 2 + 1].L });
		tr[x].mi = min({ tr[x * 2].mi, tr[x * 2 + 1].mi, tr[x * 2].miR + tr[x * 2 + 1].miL });
		tr[x].miL = min(tr[x * 2].miL, tr[x * 2].total + tr[x * 2 + 1].miL);
		tr[x].miR = min(tr[x * 2].miR + tr[x * 2 + 1].total, tr[x * 2 + 1].miR);
	}
}
seg query(vector<seg>&tr, int x, int s, int e, int l, int r) {
	if (s > r || e < l) return { -MAX, -MAX, 0, -MAX, MAX, MAX, MAX };
	else if (s >= l && e <= r) return tr[x];
	seg s1 = query(tr, x * 2, s, (s + e) / 2, l, r);
	seg s2 = query(tr, x * 2 + 1, (s + e) / 2 + 1, e, l, r);
	seg ret;
	ret.L = max(s1.L, s1.total + s2.L);
	ret.R = max(s1.R + s2.total, s2.R);
	ret.total = s1.total + s2.total;
	ret.mx = max({ s1.mx, s2.mx, s1.R + s2.L });
	ret.mi = min({ s1.mi, s2.mi, s1.miR + s2.miL });
	ret.miL = min(s1.miL, s1.total + s2.miL);
	ret.miR = min(s1.miR + s2.total, s2.miR);
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	cin >> H >> W >> T;
	htr.assign(H + 1, vector<seg>(4 * W + 1));
	wtr.assign(W + 1, vector<seg>(4 * H + 1));

	vector<vector<ll>>a(H + 1, vector<ll>(W + 1));
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> a[i][j];
			update(htr[i], 1, 1, W, j, a[i][j]);
			update(wtr[j], 1, 1, H, i, a[i][j]);
		}
	}
	while (T--) {
		int k; cin >> k;
		if (k == 1) {
			ll ans = -MAX;
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			seg up = query(htr[x1], 1, 1, W, y1, y2);
			seg down = query(htr[x2], 1, 1, W, y1, y2);
			seg left = query(wtr[y1], 1, 1, H, x1, x2);
			seg right = query(wtr[y2], 1, 1, H, x1, x2);

			//한 줄
			ans = max({ ans, up.mx, down.mx, left.mx, right.mx });
			//ㄴ자
			ans = max(ans, up.L + left.L - a[x1][y1]);
			ans = max(ans, left.R + down.L - a[x2][y1]);
			ans = max(ans, down.R + right.R - a[x2][y2]);
			ans = max(ans, right.L + up.R - a[x1][y2]);
			// ㄷ자
			ans = max(ans, query(htr[x1], 1, 1, W, y1 + 1, y2 - 1).total + left.L + right.L);
			ans = max(ans, query(wtr[y1], 1, 1, H, x1 + 1, x2 - 1).total + up.L + down.L);
			ans = max(ans, query(htr[x2], 1, 1, W, y1 + 1, y2 - 1).total + left.R + right.R);
			ans = max(ans, query(wtr[y2], 1, 1, H, x1 + 1, x2 - 1).total + up.R + down.R);
			// C 자
			ans = max(ans, left.total + down.total - a[x2][y1] + query(htr[x1], 1, 1, W, y1 + 1, y2 - 1).L + query(wtr[y2], 1, 1, H, x1 + 1, x2 - 1).R);
			ans = max(ans, down.total + right.total - a[x2][y2] + query(wtr[y1], 1, 1, H, x1 + 1, x2 - 1).R + query(htr[x1], 1, 1, W, y1 + 1, y2 - 1).R);
			ans = max(ans, right.total + up.total - a[x1][y2] + query(wtr[y1], 1, 1, H, x1 + 1, x2 - 1).L + query(htr[x2], 1, 1, W, y1 + 1, y2 - 1).R);
			ans = max(ans, up.total + left.total - a[x1][y1] + query(htr[x2], 1, 1, W, y1 + 1, y2 - 1).L + query(wtr[y2], 1, 1, H, x1 + 1, x2 - 1).L);
			// 중간에 하나 빼고
			ll total = up.total + down.total + left.total + right.total;
			total -= a[x1][y1] + a[x1][y2] + a[x2][y1] + a[x2][y2];
			ans = max({ ans, total - up.mi, total - down.mi, total - left.mi, total - right.mi });
			// 전체
			ans = max(ans, total);

			cout << ans << '\n';
		}
		else {
			int x, y; ll w; cin >> x >> y >> w;
			update(htr[x], 1, 1, W, y, w - a[x][y]);
			update(wtr[y], 1, 1, H, x, w - a[x][y]);
			a[x][y] = w;
		}
	}
}