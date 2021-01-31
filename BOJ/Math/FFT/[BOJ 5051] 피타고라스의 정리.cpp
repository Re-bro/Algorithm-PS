/* [BOJ 5051] 피타고라스 정리
	Algorithm : FFT

	k = 1 ~ n-1 의 모든 자연수에 대해서 k^2의 mod값의 출현 빈도를 벡터 a에 저장해둔다.
	그 다음, k^2 mod n 을 차수, k^2 mod n의 출현 빈도를 계수로 하는 다항식을 만들면, 
	해당 다항식을 제곱했을 때의 각 차수별 계수가 a^2 + b^2 의 경우의 수이다. 
	여기서, a <=b 인 경우만 고려해야하므로, a == b를 제외한 나머지 경우들은 절반으로 나누어준다.
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
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<ll>a(n), same(n);
	for (int i = 1; i < n; i++) {
		int k = (1LL * i*i) % n;
		a[k]++;
		same[(2LL * i*i) % n]++;
	}
	ll ans = 0;
	vector<ll> res = multiply(a, a);
	for (int i = 0; i <n; i++) {
		ll k = (same[i%n] + res[i] + res[i+n]) / 2;
		ans += 1LL* k * a[i%n];
	}
	cout << ans;
}