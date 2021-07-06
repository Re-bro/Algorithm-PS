/*
	[BOJ 13548] ¼ö¿­°ú Äõ¸® 6
	Algorithm : mo's algorithm / offline query
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define pb push_back
using namespace std;

int a[101010], cnt[101010], ans[101010], num[101010];
int n, m;
bool cmp(tuple<int, int, int> x, tuple<int, int, int> y) {
	auto [a, b, c] = x;
	auto [d, e, f] = y;
	int rt = (int)sqrt(n);
	if (b / rt == e / rt) {
		return a < d;
	}
	return b / rt < e / rt;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	vector<tuple<int, int, int>> q;
	for (int i = 1; i <= m; i++) {
		int l, r; cin >> l >> r;
		q.pb(make_tuple(l, r, i));
	}
	sort(all(q), cmp);
	int L = 1, R = 0;
	int mx = 0;
	for (auto [l, r, i] : q) {
		while (L < l) {
			cnt[a[L]]--;
			num[cnt[a[L]] + 1]--;
			num[cnt[a[L]]]++;
			if (mx == cnt[a[L]] + 1 && num[cnt[a[L]] + 1] == 0) {
				while (num[mx] == 0) {
					mx--;
				}
			}
			L++;
		}
		while (L > l) {
			cnt[a[--L]]++;
			num[cnt[a[L]] - 1]--;
			num[cnt[a[L]]]++;
			if (cnt[a[L]] > mx) mx = cnt[a[L]];
		}
		while (R < r) {
			cnt[a[++R]]++;
			num[cnt[a[R]] - 1]--;
			num[cnt[a[R]]]++;
			if (cnt[a[R]] > mx) mx = cnt[a[R]];
		}
		while (R > r) {
			cnt[a[R]]--;
			num[cnt[a[R]] + 1]--;
			num[cnt[a[R]]]++;
			if (mx == cnt[a[R]] + 1 && num[cnt[a[R]] + 1] == 0) {
				while (num[mx] == 0) mx--;
			}
			R--;
		}
		ans[i] = mx;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
}