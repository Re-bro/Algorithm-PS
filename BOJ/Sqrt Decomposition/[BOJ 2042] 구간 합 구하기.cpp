/*
	[BOJ 2042] 구간 합 구하기
	Algorithm : Sqrt decomposition
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[1010101], sq[1010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int rt = (int)sqrt(n);
	for (int i = 1; i <= n; i++) {
		sq[i / rt] += a[i];
	}
	for (int i = 1; i <= m + k; i++) {
		ll x, y, z; cin >> x >> y >> z;
		if (x == 1) {
			sq[y / rt] += z - a[y];
			a[y] = z;
		}
		else {
			ll res = 0;
			while (y%rt != 0 && y <= z) res += a[y++];
			while (z % rt != rt - 1 && y <= z) res += a[z--];
			while (y <= z) {
				res += sq[y / rt];
				y += rt;
			}
			cout << res << '\n';
		}
	}
}