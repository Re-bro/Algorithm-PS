/*
	[BOJ 15957] À½¾Ç ÃßÃµ
	Algorithm : PBS / Fenwick Tree / Euler Tour Technique
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

int sub[101010], in[101010], out[101010], L[101010], R[101010], ans[101010], P[101010];
vector<int> adj[101010], S[101010], g[101010];
ll tr[101010];
int num, n, k, J;
void update(int x, int val) {
	while (x <= n) {
		tr[x] += val;
		x += (x&-x);
	}
}
ll sum(int x) {
	ll res = 0;
	while (x > 0) {
		res += tr[x];
		x -= (x&-x);
	}
	return res;
}
void dfs(int u) {
	in[u] = ++num;
	sub[in[u]] = 1;
	for (int v : adj[u]) {
		dfs(v);
		sub[in[u]] += sub[in[v]];
	}
	out[u] = num;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n >> k >> J;
	for (int i = 2; i <= n; i++) {
		int a; cin >> a;
		adj[a].pb(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		cin >> P[i];
		S[P[i]].pb(i);
		L[i] = 1;
		R[i] = k;
		ans[i] = -1;
	}
	vector<pair<int, pii>> v;
	for (int i = 1; i <= k; i++) {
		int t, p, s; cin >> t >> p >> s;
		v.pb({ t, {p, s} });
	}
	sort(all(v));
	while (1) {
		bool chk = false;
		ini(tr, 0);
		for (int i = 1; i <= k; i++) g[i].clear();
		for (int i = 1; i <= n; i++) {
			if (L[i] <= R[i]) {
				chk = true;
				g[(L[i] + R[i]) / 2].pb(i);
			}
		}
		if (!chk) break;
		for (int i = 1; i <= k; i++) {
			int t = v[i-1].first;
			auto[p, s] = v[i - 1].second;
			update(in[p], s / sub[in[p]]);
			update(out[p] + 1, -(s / sub[in[p]]));
			for (int j : g[i]) { 
				ll val = 0;
				for (int q : S[j]) {
					val += sum(in[q]);
					if (val > 1LL * J*sz(S[j])) break;
				}
				if (val > 1LL*J*sz(S[j])) {
					R[j] = i - 1;
					ans[j] = t;
				}
				else L[j] = i + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[P[i]] << '\n';
	}
}