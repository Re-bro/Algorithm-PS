/*
	[CF 1484C] Basic Diplomacy
	Algorithm : Greedy / Sorting
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;
vector<int> v[100001];
int cnt[100001];
int n, m, mxnum, k;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		cin >> n >> m;
		int mx = 0;
		for (int i = 1; i <= n; i++) cnt[i] = 0;
		for (int i = 1; i <= m; i++) v[i].clear();
		for (int i = 1; i <= m; i++) {
			cin >> k;
			while (k--) {
				int a; cin >> a;
				v[i].push_back(a);
			}
			cnt[v[i][0]]++;
			if (mx < cnt[v[i][0]]) {
				mx = cnt[v[i][0]];
				mxnum = v[i][0];
			}
		}
		if (mx > (m + 1) / 2) {
			for (int i = 1; i <= m; i++) {
				if (mxnum == v[i][0]) {
					if (sz(v[i]) > 1) {
						swap(v[i][0], v[i][1]);
						mx--;
					}
					if (mx <= (m + 1) / 2) break;
				}
			}
		}
		if (mx > (m + 1) / 2) cout << "NO\n";
		else {
			cout << "YES\n";
			for (int i = 1; i <= m; i++) cout << v[i][0] << ' ';
			cout << '\n';
		}
	}
}