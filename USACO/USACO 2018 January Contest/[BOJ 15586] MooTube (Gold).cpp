/*
	[BOJ 15586] MooTube (Gold)
	Algorithm : Disjoint-set / Offline query
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

int P[101010];
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
	int n, q; cin >> n >> q;
	ini(P, -1);
	vector<tuple<int, int, int>> edge;
	for (int i = 1; i < n; i++) {
		int p, q, r; cin >> p >> q >> r;
		edge.pb(make_tuple(-r, p, q));
	}
	sort(all(edge));
	vector<tuple<int, int, int>> query;
	for (int i = 0; i < q; i++) {
		int k, v; cin >> k >> v;
		query.pb(make_tuple( -k, v ,i));
	}
	sort(all(query));
	int s = 0;
	vector<int> ans(q);
	for (auto[k, v, i] : query) {
		while (s < n-1) {
			auto[r, p, q] = edge[s];
			if (r <= k) {
				merge(p, q);
				s++;
			}
			else break;
		}
		ans[i] = -P[find(v)] - 1;
	}
	for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}