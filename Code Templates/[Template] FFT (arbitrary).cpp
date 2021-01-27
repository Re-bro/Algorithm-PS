/* FFT algorithm with arbitrary precision in long long integer range

	Time Complexity : O(nlogn)
	Space Complexity : O(n)
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
using namespace std;
using cdbl = complex<double>;
using ll = long long;
void fft(vector<cdbl> &a, bool inv) {
	int n = sz(a);
	int j = 0;
	for (int i = 1; i < n; i++) {
		int bit = (n >> 1);
		while (j >= bit) {
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * acos(-1) / len * (inv ? -1 : 1);
		cdbl wlen(cos(ang), sin(ang)); //(wlen)^len= 1
		for (int i = 0; i < n; i += len) {
			cdbl w(1);
			for (int j = 0; j < len / 2; j++) {
				cdbl u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (inv) for (int i = 0; i < n; i++) a[i] /= n;
}
vector<ll> multiply(const vector<int>&a, const vector<int>&b, ll mod) {
	int n = 1;
	while (n <= max(sz(a), sz(b))) n <<= 1;
	int shift = 15, mask = (1 << shift) - 1;
	vector<cdbl> fa(n, cdbl(0, 0)), fb(n, cdbl(0, 0));
	for (int i = 0; i < sz(a); i++) fa[i] = cdbl(a[i] >> shift, a[i] & mask);
	for (int i = 0; i < sz(b); i++) fb[i] = cdbl(b[i] >> shift, b[i] & mask);
	fft(fa, false); fft(fb, false);
	vector<cdbl>f1g1_f1g2(n), f2g1_f2g2(n);
	for (int i = 0; i < n; i++) {
		cdbl f1 = (fa[i] + conj(fa[(n - i) % n]))*cdbl(0.5, 0);
		cdbl f2 = (fa[i] - conj(fa[(n - i) % n]))*cdbl(0, -0.5);
		cdbl g1 = (fb[i] + conj(fb[(n - i) % n]))*cdbl(0.5, 0);
		cdbl g2 = (fb[i] - conj(fb[(n - i) % n]))*cdbl(0, -0.5);
		f1g1_f1g2[i] = f1 * g1 + f1 * g2*cdbl(0, 1);
		f2g1_f2g2[i] = f2 * g1 + f2 * g2*cdbl(0, 1);
	}
	fft(f1g1_f1g2, true); fft(f2g1_f2g2, true);
	vector<ll> ret(n);
	for (int i = 0; i < n; i++) {
		ll f1g1 = (ll)round(f1g1_f1g2[i].real());
		ll f1g2 = (ll)round(f1g1_f1g2[i].imag());
		ll f2g1 = (ll)round(f2g1_f2g2[i].real());
		ll f2g2 = (ll)round(f2g1_f2g2[i].imag());
		if (mod) {
			f1g1 %= mod; f1g2 %= mod; f2g1 %= mod; f2g2 %= mod;
		}
		ret[i] = (f1g1 << (2 * shift)) + (((f1g2 + f2g1) % mod) << shift) + f2g2;
		if (mod) {
			ret[i] %= mod;
			ret[i] = (ret[i] + mod) % mod;
		}
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<int> f(n + 1), g(m + 1);
	for (int i = 0; i <= n; i++) cin >> f[i];
	for (int i = 0; i <= m; i++) cin >> g[i];
	vector<ll> mul = multiply(f, g, 0);
	int ans = 0;
	for (int i = 0; i < sz(mul); i++) ans ^= mul[i];
	cout << ans;
}