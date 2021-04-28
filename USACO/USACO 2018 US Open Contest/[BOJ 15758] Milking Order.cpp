/*
	[BOJ 15758] Milking Order
	Algorithm : Binary Search / Topological sort
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define pb push_back
using namespace std;
int n, m, in[101010]; 
vector<int> order[50505], adj[101010], ans;
bool sol(int mid) {
	for (int i = 1; i <= n; i++) adj[i].clear(), in[i] = 0;
	for (int i = 1; i <= mid; i++) {
		for (int j = 0; j < sz(order[i]) - 1; j++) {
			adj[order[i][j]].pb(order[i][j + 1]);
			in[order[i][j + 1]]++;
		}
	}
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			pq.push(-i);
		}
	}
	vector<int> tmp;
	while (!pq.empty()) {
		int u = pq.top(); pq.pop();
		tmp.pb(-u);
		for (int v : adj[-u]) {
			in[v]--;
			if (in[v] == 0) {
				pq.push(-v);
			}
		}
	}
	if (sz(tmp) == n) {
		ans = tmp;
		return true;
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int k; cin >> k;
		while (k--) {
			int a; cin >> a;
			order[i].pb(a);
		}
	}
	int s = 1, e = m;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (sol(mid)) s = mid + 1;
		else e = mid - 1;
	}
	for (int i : ans) cout << i << ' ';
}