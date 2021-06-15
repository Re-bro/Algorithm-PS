/*
	[BOJ 16977] 히스토그램에서 가장 큰 직사각형과 쿼리
	Algorithm : Segment Tree / PBS
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
struct seg {
	int l, r, mid;
};

pii h[101010];
int L[101010], R[101010], ans[101010];
seg tr[404040];
vector<int> g[101010];
void update(int x, int s, int e, int i) {
	if (i > e || i < s) return;
	if (s == e) {
		tr[x].l = tr[x].r = tr[x].mid = 1;
		return;
	}
	else {
		update(x * 2, s, (s + e) / 2, i);
		update(x * 2 + 1, (s + e) / 2 + 1, e, i);
		if (tr[x * 2].mid == (s + e) / 2 - s + 1) tr[x].l = tr[x * 2].mid + tr[x * 2 + 1].l;
		else tr[x].l = tr[x * 2].l;
		if (tr[x * 2 + 1].mid == e - (s + e) / 2) tr[x].r = tr[x * 2 + 1].mid + tr[x * 2].r;
		else tr[x].r = tr[x * 2 + 1].r;
		tr[x].mid = max({ tr[x * 2].r + tr[x * 2 + 1].l, tr[x * 2].mid, tr[x * 2 + 1].mid , tr[x].l, tr[x].r});
	}
}
seg mx(int x, int s, int e, int l, int r) {
	if (s > r || e < l) return { 0, 0, 0 };
	else if (s >= l && e <= r) return tr[x];
	else {
		seg s1 = mx(x * 2, s, (s + e) / 2, l, r);
		seg s2 = mx(x * 2 + 1, (s + e) / 2 + 1, e, l, r);
		int l = s1.l;
		int r = s2.r;
		if (s1.mid == (s + e) / 2 - s + 1) l = s1.mid + s2.l;
		else l = s1.l;
		if (s2.mid == e - (s + e) / 2) r = s2.mid + s1.r;
		else r = s2.r;
		int mid = max({ s1.r + s2.l, s1.mid, s2.mid});
		return { l, r, mid };
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i].first, h[i].second = i;
	sort(h + 1, h + 1 + n, greater<pii>());
	int q; cin >> q;
	vector<pair<pii, int>> query;
	for (int i = 1; i <= q; i++) {
		int l, r, w; cin >> l >> r >> w;
		query.pb({ {l, r}, w });
	}
	for (int i = 0; i < q; i++) L[i] = 1, R[i] = n;
	while (1) {
		bool chk = false;
		ini(tr, 0);
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 0; i < q; i++) {
			if (L[i] <= R[i]) {
				chk = true;
				g[(L[i] + R[i]) / 2].pb(i);
			}
		}
		if (!chk) break;
		for (int i = 1; i <= n; i++) {
			update(1, 1, n, h[i].second);
			for (int j : g[i]) {
				if (mx(1, 1, n, query[j].first.first, query[j].first.second).mid >= query[j].second) {
					R[j] = i - 1;
					ans[j] = h[i].first;
				}
				else L[j] = i + 1;
			}
		}
	}
	for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}