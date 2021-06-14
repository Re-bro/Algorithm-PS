#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[101010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= q; i++) {
		ll k; cin >> k;
		int prv = 0;
		while (1) {
			int cnt = upper_bound(a + 1, a + 1 + n, k) - a - 1;
			if (cnt != prv) {
				k += cnt - prv;
				prv = cnt;
			}
			else {
				cout << k << '\n';
				break;
			}
		}
	}
}