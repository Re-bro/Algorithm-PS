/* [BOJ 20176] Needle
	Algorithm : FFT

	barriers를 순서대로 a,b,c라고 하면, 2b = a+c 를 만족하는 세 점을 찾는 문제이다. 
	따라서, 두 수를 뽑아 만드는 합의 모든 경우의 수를 구하는 과정이 필요하고, 
	원소의 개수가 각각 최대 5만이므로 nlogn인 FFT를 이용한다.
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
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
		cdbl wlen(cos(ang), sin(ang)); 
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
	while (n < max(sz(a), sz(b))) n <<= 1;
	n <<= 1;
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
	int u; cin >> u;
	int val;
	vector<int>a(60001), b(60001), c(60001);
	for (int i = 1; i <= u; i++) {
		cin >> val;
		a[val + 30000] = 1;
	}
	cin >> u;
	for (int i = 1; i <= u; i++) {
		cin >> val;
		b[val + 30000] = 1;
	}
	cin >> u;
	for (int i = 1; i <= u; i++) {
		cin >> val;
		c[val + 30000] = 1;
	}
	vector<int> res = multiply(a, c);
	int ans = 0;
	for (int i = 0; i <= 60000; i++) {
		if (b[i] == 1) ans += res[2 * i];
	}
	cout << ans;
}