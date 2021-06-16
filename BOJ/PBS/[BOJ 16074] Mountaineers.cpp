/*
	[BOJ 16074] Mountaineers
	Algorithm : PBS / Disjoint-Set
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

int h[505][505];
struct path {
	int x1, y1, x2, y2;
};
path Q[101010];
int L[101010], R[101010], ans[101010], P[250505];
vector<int> g[505050];
vector<pair<int, pii>> edge;
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
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> h[i][j];
	}
	for (int i = 1; i <= q; i++) {
		cin >> Q[i].x1 >> Q[i].y1 >> Q[i].x2 >> Q[i].y2;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i < n) edge.pb({ max(h[i][j], h[i + 1][j]), {i*m + j, (i + 1)*m + j} });
			if (j < m) edge.pb({ max(h[i][j], h[i][j + 1]), {i*m + j, i*m + j + 1} });
		}
	}
	sort(all(edge));
	for (int i = 1; i <= q; i++) L[i] = 1, R[i] = sz(edge);
	while (1) {
		ini(P, -1);
		bool chk = false;
		for (int i = 1; i <= sz(edge); i++) g[i].clear();
		for (int i = 1; i <= q; i++) {
			if (L[i] <= R[i]) {
				chk = true;
				g[(L[i] + R[i]) / 2].pb(i);
			}
		}
		if (!chk) break;
		for (int i = 0; i < sz(edge); i++) {
			merge(edge[i].second.first, edge[i].second.second);
			for (int j : g[i+1]) {
				if (find(Q[j].x1*m + Q[j].y1) == find(Q[j].x2*m + Q[j].y2)) {
					ans[j] = edge[i].first;
					R[j] = i;
				}
				else {
					L[j] = i + 2;
				}
			}
		}
	}
	for (int i = 1; i <= q; i++){
		if (Q[i].x1 == Q[i].x2 && Q[i].y1 == Q[i].y2) cout << h[Q[i].x1][Q[i].y1] << '\n';
		else cout << ans[i] << '\n';
	}
}