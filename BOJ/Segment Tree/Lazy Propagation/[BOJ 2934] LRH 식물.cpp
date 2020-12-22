/* [BOJ 2934] LRH ½Ä¹°
	Algorithm : Segment Tree / Lazy propagation
*/

#include<bits/stdc++.h>
using namespace std;
int tr[400001];
int lazy[400001];
void update_lazy(int x, int s, int e);
int sum(int x, int s, int e, int l, int r) {
	update_lazy(x, s, e);
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tr[x];
	else return sum(x * 2, s, (s + e) / 2, l, r) + sum(x * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
void update_range(int x, int s, int e, int l, int r, int dx) {
	update_lazy(x, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r) {
		tr[x] += (e - s + 1)*dx;
		if (s != e) {
			lazy[x * 2] += dx;
			lazy[x * 2 + 1] += dx;
		}
		return;
	}
	update_range(x * 2, s, (s + e) / 2, l, r, dx);
	update_range(x * 2 + 1, (s + e) / 2 + 1, e, l, r, dx);
	tr[x] = tr[x * 2] + tr[x * 2 + 1];
}
void update_lazy(int x, int s, int e) {
	if (lazy[x] != 0) {
		tr[x] += (e - s + 1)*lazy[x];
		if (s != e) {
			lazy[x * 2] += lazy[x];
			lazy[x * 2 + 1] += lazy[x];
		}
		lazy[x] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		int l, r; cin >> l >> r;
		int k1 = sum(1, 1, 100000, l, l);
		int k2 = sum(1, 1, 100000, r, r);
		cout << k1+ k2 << '\n';
		update_range(1, 1, 100000, l, l, -k1);
		update_range(1, 1, 100000, r, r, -k2);
		if (r - l > 1)	update_range(1, 1, 100000, l + 1, r - 1, 1);
	}
}