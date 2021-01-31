/* [BOJ 10531] Golf Bot
	Algorithm : FFT
	
	�������� FFT ����. 
	������ �ѹ� ���� �� ������ �Ÿ��� ��� ����� 1, �ƴϸ� 0���� �� �� ���׽��� �����Ѵ�. 
	�׸���, ���ϴ� �Ÿ��� d��� �ϸ�, d������ ����� 0���� ū ��� 2�� �ļ� d�� ������ �� �ִ�.
	1�� �ļ� �����ϴ� ���� ó���� �־��� ��ǲ���� �ذᰡ���ϴ�.
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
	//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	vector<int> v(200001);
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		v[a] = 1;
	}
	vector<int> res = multiply(v, v);
	int m; cin >> m;
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int a; cin >> a;
		if (v[a] || res[a]) ans++;
	}
	cout << ans;
}