/* [BOJ 17104] ������ ��Ƽ�� 2
	Algorithm : FFT
	
	�Ҽ��� ������ ����� 1��, �ƴϸ� 0���� �� ���׽��� ������ �̿��Ͽ� ���ϸ� ������, 
	�� ���������� �ð��� 0.5���̹Ƿ� �ܼ��� FFT�� �����ϸ� �ȵȴ�.
	����, ������ ũ�⸦ �ٿ��־�� �Ѵ�. 
	� 2�� �ƴ� �Ҽ��� p��� �ϸ�, p-1�� ¦���̹Ƿ� 2�� ������ �� �ִ�. 
	�׷��� (p-1)/2 �� �Ǵµ�, �� ���� ���� �� �ִ� �Ҽ��� p�� �����ϴ�. 
	p + q = n�� �����Ѵٰ� �ϸ�, (p-1)/2 + (q-1)/2 = (p+q)/2 - 1 = n/2 - 1 �̹Ƿ� 
	������ (p- 1)/2�� ���� ����� 1�� �����, ���׽��� ������ ���� n/2 - 1 ������ ����� Ȯ���ϸ� �ȴ�.

	n = 4�� ���� ���� ó�����־�� �Ѵ�.
 */
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
using namespace std;
vector<int>prime;

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
	prime.assign(1000001, 1);
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= 1000000; i++) {
		if (prime[i] == 1) {
			for (int j = 2; j*i <= 1000000; j++) {
				prime[i*j] = 0;
			}
		}
	}
	vector<int> v(500001);
	for (int i = 3; i <= 1000000; i++) {
		if (prime[i] == 1) v[(i - 1) / 2] = 1;
	}
	vector<int> res = multiply(v, v);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		if (n == 4) cout << 1 << '\n';
		else cout << (res[n / 2 - 1] + prime[n / 2]) / 2 << '\n';
	}
}