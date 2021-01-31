/* [BOJ 14756] Telescope
	Algorithm : FFT

	�־��� P 2���� �迭�� �¿�� ��������, �� �ึ�� ������ ������ ������ ����.
	T�� ù���� a0, a1, a2, ... an-1 , P�� ù���� b0, b1, b2, ..., bl-1�̶�� �ϸ�
	a0bl-1 + a1bl-2 + ... + al-1b0 / a1bl-1 + a2bl-2 + ... + alb0 / ... 
	���� �ึ�� FFT�� �������ָ�, �ð����⵵�� O(logn*(ml))�� �ȴ�. 
	�� ���� ������ִ� ������ O(nm)�̹Ƿ� �ð����� ����Ѵ�.
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
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
vector<ll> multiply(const vector<ll>&a, const vector<ll>&b) {
	vector<cdbl> fa(all(a)), fb(all(b));
	int n = 1;
	while (n < max(sz(a), sz(b))) n <<= 1;
	n <<= 1;
	fa.resize(n); fb.resize(n);
	fft(fa, false); fft(fb, false);
	for (int i = 0; i < n; i++) fa[i] *= fb[i];
	fft(fa, true);
	vector<ll> res(n);
	for (int i = 0; i < n; i++) res[i] = int(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
	return res;
}
vector<vector<ll>>T, P, C;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, l, m; cin >> n >> l >> m;
	ll W; cin >> W;
	T.assign(m, vector<ll>(n));
	P.assign(m, vector<ll>(l));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> T[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < l; j++) {
			cin >> P[i][l - 1 - j];
		}
	}
	for (int i = 0; i < m; i++) {
		C.push_back(multiply(T[i], P[i]));
	}
	int ans = 0;
	for (int i = 0; i <= n - l; i++) {
		ll k = 0;
		for (int j = 0; j < m; j++) {
			k += C[j][i + l-1];
		}
		if (k > W) ans++;
	}
	cout << ans;
}