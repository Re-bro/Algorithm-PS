/*
	[BOJ 17082] Äõ¸®¿Í Äõ¸®
	Algorithm : Set / Greedy
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

int a[202020], l[202020], r[202020], in[202020];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) cin >> l[i];
	for (int i = 1; i <= m; i++) cin >> r[i];
	sort(l + 1, l + 1 + m);
	sort(r + 1, r + 1 + m);
	bool chk = true;
	for (int i = 1; i <= m; i++) {
		if (l[i] > r[i]) chk = false;
		in[l[i]]++;
		in[r[i] + 1]--;
	}
	set<pii> s;
	for (int i = 1; i <= n; i++) {
		in[i] += in[i - 1];
		if (in[i] > 0) s.insert({ a[i], i });
	}
	for (int i = 1; i <= q; i++) {
		int x, y; cin >> x >> y;
		if (in[x] > 0 && in[y] <= 0) {
			s.erase({ a[x], x });
			s.insert({ a[y], x });
		}
		else if (in[y] > 0 && in[x] <= 0) {
			s.erase({ a[y], y });
			s.insert({ a[x], y });
		}
		else if (in[x] > 0 && in[y] > 0) {
			s.erase({ a[x], x });
			s.erase({ a[y], y });
			s.insert({ a[x], y });
			s.insert({ a[y], x });
		}
		swap(a[x], a[y]);
		if (!chk) cout << 1000000000 << '\n';
		else cout << (*s.rbegin()).first << '\n';
	}
}