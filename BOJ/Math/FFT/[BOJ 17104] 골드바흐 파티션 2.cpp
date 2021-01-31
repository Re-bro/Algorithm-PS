/* [BOJ 17104] 골드바흐 파티션 2
	Algorithm : FFT
	
	소수인 차수는 계수를 1로, 아니면 0으로 둔 다항식의 제곱을 이용하여 구하면 되지만, 
	이 문제에서는 시간이 0.5초이므로 단순히 FFT를 적용하면 안된다.
	따라서, 벡터의 크기를 줄여주어야 한다. 
	어떤 2가 아닌 소수를 p라고 하면, p-1은 짝수이므로 2로 나눠줄 수 있다. 
	그러면 (p-1)/2 가 되는데, 이 값을 만들 수 있는 소수는 p로 유일하다. 
	p + q = n을 만족한다고 하면, (p-1)/2 + (q-1)/2 = (p+q)/2 - 1 = n/2 - 1 이므로 
	차수가 (p- 1)/2인 항의 계수를 1로 만들고, 다항식을 제곱한 다음 n/2 - 1 차항의 계수를 확인하면 된다.

	n = 4인 경우는 따로 처리해주어야 한다.
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