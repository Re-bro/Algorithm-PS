#include<bits/stdc++.h>

using namespace std;

int P[10101];
int find(int a) {
	return P[a] < 0 ? a : P[a] = find(P[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (P[a] > P[b]) swap(a, b);
		P[a] += P[b];
		P[b] = a;
		return true;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, t; cin >> n >> m >> t;
	priority_queue<pair<int, pair<int, int>>> pq;
	fill(P, P + n + 1, -1);
	for (int i = 0; i < m; i++) {
		int u, v, c; cin >> u >> v >> c;
		pq.push({ -c, {u, v} });
	}
	long long ans = 0;
	while (!pq.empty()) {
		auto [d, p] = pq.top(); pq.pop();
		if (merge(p.first, p.second)) ans += -d;
	}
	int cost = 0;
	for (int i = 1; i < n; i++) {
		ans += cost;
		cost += t;
	}
	cout << ans;
}