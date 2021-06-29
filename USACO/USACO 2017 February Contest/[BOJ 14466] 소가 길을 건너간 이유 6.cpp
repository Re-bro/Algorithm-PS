/*
	[BOJ 14466] 소가 길을 건너간 이유 6
	Algorithm : Disjoint-set
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using pii = pair<int, int>;

int P[11000];
pii cow[101];
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
	int n, k, r; cin >> n >> k >> r;
	set<pii> s;
	ini(P, -1);
	for (int i = 1; i <= r; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		s.insert({ (x1-1) * n + y1, (x2-1) * n + y2 });
		s.insert({ (x2-1) * n + y2 , (x1-1) * n + y1 });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int u = (i - 1) * n + j;
			if (i < n) {
				int v = i * n + j;
				if (s.find({ u, v }) == s.end()) {
					merge(u, v);
				}
			}
			if (j < n) {
				int v = (i - 1) * n + j + 1;
				if (s.find({ u, v }) == s.end()) merge(u, v);
			}
		}
	}
	for (int i = 1; i <= k; i++) {
		cin >> cow[i].first >> cow[i].second;
	}
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = i + 1; j <= k; j++) {
			int u = (cow[i].first - 1) * n + cow[i].second;
			int v = (cow[j].first - 1) * n + cow[j].second;
			if (find(u) != find(v)) ans++;
		}
	}
	cout << ans;
}