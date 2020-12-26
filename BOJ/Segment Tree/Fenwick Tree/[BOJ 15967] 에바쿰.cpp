/* [BOJ 15967] ¿¡¹ÙÄñ
	Algorithm : Lazy propagation with fenwick tree
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, q1, q2;
ll a_tr[1000001];
ll b_tr[1000001];
ll psum[1000001];
ll sum(ll tr[], int i) {
	ll ans = 0;
	while (i > 0) {
		ans += tr[i];
		i -= (i & -i);
	}
	return ans;
}
void update(ll tr[], int i, ll val) {
	while (i <= n) {
		tr[i] += val;
		i += (i & -i);
	}
}
void r_update(int l, int r, int x) {
	update(a_tr, l, x); update(a_tr, r + 1, -x);
	update(b_tr, l, 1LL* (-l + 1) * x); update(b_tr, r + 1, 1LL* r * x);
}
ll r_sum(int l, int r) {
	return sum(a_tr, r) * r + sum(b_tr, r) - sum(a_tr, l - 1) * (l - 1) - sum(b_tr, l - 1);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q1 >> q2;
	int a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		psum[i] = psum[i - 1] + a;
	}
	for (int i = 1; i <= q1 + q2; i++) {
		int k; cin >> k;
		if (k == 1) {
			ll l, r; cin >> l >> r;
			cout<<psum[r] - psum[l-1] + r_sum(l, r)<<'\n';
		}
		else {
			ll l, r, x; cin >> l >> r >> x;
			r_update(l, r, x);
		}
	}
}