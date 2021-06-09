/*
	[BOJ 1396] 크루스칼의 공
	Algorithm : Union-Find / Parallel Binary Search
	//O(logm(m+Q)) : while문 횟수 = logm, 간선 한번 스위핑 = m, 쿼리들 갱신하는 횟수 = Q
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;

int P[101010], l[101010], r[101010];
pii ans[101010];
vector<int> g[101010];
int find(int a) {
	return P[a] < 0 ? a : P[a] = find(P[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (P[a] > P[b]) swap(a, b);
		P[a] += P[b];
		P[b] = a;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	int n, m; cin >> n >> m;
	vector<pair<int, pii>> edge;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge.pb({ c, {a, b} });
	}
	sort(all(edge));
	int q; cin >> q;
	vector<pii> query(q);
	for (int i = 0; i < q; i++) {
		cin >> query[i].fi >> query[i].se;
	}
	for (int i = 0; i < q; i++) l[i] = 1, r[i] = m;
	while (1) {
		for (int i = 1; i <= m; i++) g[i].clear();
		bool chk = false;
		// O(Qlogm)
		for (int i = 0; i < q; i++) {
			if (l[i] <= r[i]) {
				chk = true;
				g[(l[i] + r[i]) / 2].pb(i);
			}
		}
		if (!chk) break;
		ini(P, -1);
		//O(m + Q)
		for (int i = 1; i <= m; i++) {
			merge(edge[i - 1].se.fi, edge[i - 1].se.se);
			for (int j : g[i]) {
				if (find(query[j].fi) == find(query[j].se)) {
					ans[j].fi = edge[i - 1].fi;
					ans[j].se = -P[find(query[j].fi)];
					r[j] = i - 1;
				}
				else l[j] = i + 1;
			}
		}
	}
	for (int i = 0; i < q; i++) {
		if (l[i] > m) cout << -1 << '\n';
		else cout << ans[i].fi << ' ' << ans[i].se << '\n';
	}
}