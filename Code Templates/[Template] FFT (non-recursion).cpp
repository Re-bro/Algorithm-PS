/* FFT algorithm by non-recursion
	Time Complexity : O(nlogn)
	Space Complexity : O(n)
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
using namespace std;
using cdbl = complex<double>;

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
vector<int> multiply(const vector<int>&a, const vector<int>&b) {
	vector<cdbl> fa(all(a)), fb(all(b));
	int n = 1;
	while (n <= max(sz(a), sz(b))) n <<= 1;
	fa.resize(n); fb.resize(n);
	fft(fa, false); fft(fb, false);
	for (int i = 0; i < n; i++) fa[i] *= fb[i];
	fft(fa, true);
	vector<int> res(n);
	for (int i = 0; i < n; i++) res[i] = int(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<int> f(n + 1), g(m + 1);
	for (int i = 0; i <= n; i++) cin >> f[i];
	for (int i = 0; i <= m; i++) cin >> g[i];
	vector<int> mul = multiply(f, g);
	int ans = 0;
	for (int i = 0; i < sz(mul); i++) ans ^= mul[i];
	cout << ans;
}