/*
	[BOJ 8217] À¯¼º
	Algorithm : Parallel Binary Search / Fenwick Tree
*/

#include<bits/stdc++.h>
#define pb push_back

using namespace std;
using ll = long long;

ll p[300001];
ll tr[300001];
int L[300001], R[300001], ans[300001];
vector<int> have[300001], g[300001];
int n, m;
ll sum(int i) {
	ll res = 0;
	while (i > 0) {
		res += tr[i];
		i -= (i & -i);
	}
	return res;
}
void update(int i, ll val) {
	while (i <= m) {
		tr[i] += val;
		i += (i & -i);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int o; cin >> o;
		have[o].pb(i);
	}
	for (int i = 1; i <= n; i++) cin >> p[i];
	int q; cin >> q;
	vector<tuple<int, int, ll, int>> Q;
	for (int i = 1; i <= q; i++) {
		int l, r; ll a; cin >> l >> r >> a;
		Q.emplace_back(l, r, a, i);
	}
	for (int i = 1; i <= n; i++) L[i] = 1, R[i] = q;
	while (1) {
		bool chk = false;
		for (int i = 1; i <= m; i++) tr[i] = 0;
		for (int i = 1; i <= q; i++) g[i].clear();
		for (int i = 1; i <= n; i++) {
			if (L[i] <= R[i]) {
				g[(L[i] + R[i]) / 2].pb(i);
				chk = true;
			}
		}
		if (!chk) break;
		for (auto[l, r, a, i] : Q) {
			if (l <= r) {
				update(l, a);
				update(r + 1, -a);
			}
			else {
				update(1, a);
				update(l, a);
				update(r + 1, -a);
			}
			for (int j : g[i]) {
				ll s = 0;
				for (int k : have[j]) {
					s += sum(k);
					if (s >= p[j]) break;
				}
				if (s >= p[j]) {
					ans[j] = i;
					R[j] = i - 1;
				}
				else L[j] = i + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 0) cout << "NIE\n";
		else cout << ans[i] << '\n';
	}
}