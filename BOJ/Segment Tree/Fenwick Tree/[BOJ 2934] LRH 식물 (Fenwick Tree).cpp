/* [BOJ 2934] LRH ½Ä¹° 
	Algorithm : Fenwick Tree

	Range update & point query
*/

#include<bits/stdc++.h>

using namespace std;
int tr[100001];
int sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += tr[i];
		i -= (i&-i);
	}
	return ans;
}
void update(int i, int val) {
	while (i < 100001) {
		tr[i] += val;
		i += (i&-i);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		int l, r; cin >> l >> r;
		int k1 = sum(l);
		int k2 = sum(r);
		cout << sum(l) + sum(r) << '\n';
		update(l, -k1); update(l + 1, k1);
		update(r, -k2); update(r + 1, k2);
		if (r - l > 1) {
			update(l + 1, 1); update(r, -1);
		}
	}
}