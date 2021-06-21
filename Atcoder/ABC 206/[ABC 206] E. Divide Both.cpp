#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define pb push_back
using namespace std;
using ll = long long;

int prime[1001];
vector<int> P;
int l, r;
ll sol(vector<int>& fac, int i) {
	ll res = 0;
	for (int sub = (1 << sz(fac)) - 1; sub; sub = (sub - 1) & (1 << (sz(fac))) - 1) {
		int val = 1;
		int cnt = 0;
		for (int j = 0; j < sz(fac); j++) {
			if ((1 << j) & sub) {
				val *= fac[j];
				cnt++;
			}
		}
		if (val != 1) {
			int k = r / val - i / val;
			if (cnt % 2) res += k;
			else res -= k;
		}
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	for (int i = 2; i <= 1000; i++) {
		if (prime[i] == 0) {
			P.pb(i);
			for (int j = 2; j * i <= 1000; j++) {
				prime[i * j] = 1;
			}
		}
	}
	ll ans = 0;
	cin >> l >> r;
	for (int i = max(2, l); i < r; i++) {
		int k = i;
		vector<int> fac;
		int idx = 0;
		for (int i = 0; i < sz(P); i++) {
			if (k == 1) break;
			if (k % P[i] == 0) {
				fac.pb(P[i]);
				while (k % P[i] == 0) k /= P[i];
			}
		}
		if (k > 1) fac.pb(k);
		ans += sol(fac, i);
		ans -= r / i - 1;
	}
	cout << ans * 2;
}