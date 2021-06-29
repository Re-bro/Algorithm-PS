/*
	[BOJ 13547] ¼ö¿­°ú Äõ¸® 5
	Algorithm : Mo's Algorithm / Offline Query
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

int a[101010], res[101010];
int cnt[1010101];
int n;
bool cmp(tuple<int, int, int> x, tuple<int, int, int> y) {
	int rt = (int)sqrt(n);
	auto[q, w, n1] = x;
	auto[e, r, n2] = y;
	if (w / rt == r / rt) return q < e;
	else return w / rt < r / rt;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int m; cin >> m;
	vector<tuple<int, int, int>> q;
	for (int i = 1; i <= m; i++) {
		int l, r; cin >> l >> r;
		q.push_back(make_tuple(l, r, i));
	}
	sort(all(q), cmp);
	int l = 1, r = 0;
	int ans = 0;
	for (auto[x, y, i] : q) {
		while (x < l) {
			l--;
			if (++cnt[a[l]] == 1) ans++;
		}
		while (x > l) {
			if (--cnt[a[l]] == 0) ans--;
			l++;
		}
		while (y < r) {
			if (--cnt[a[r]] == 0) ans--;
			r--;
		}
		while (y > r) {
			r++;
			if (++cnt[a[r]] == 1) ans++;
		}
		res[i] = ans;
	}
	for (int i = 1; i <= m; i++) cout << res[i] << '\n';
}