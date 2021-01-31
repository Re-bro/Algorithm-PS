/* [BOJ 7677] Fibonacci
	Algorithm : Exponentiation by squaring

*/
#include<bits/stdc++.h>
using namespace std;
const int MOD = 10000;
struct mat {
	int a, b, c, d;
	mat operator *(mat x) {
		mat res;
		res.a = (a * x.a + b * x.c)%MOD;
		res.b = (a * x.b + b * x.d)%MOD;
		res.c = (c * x.a + d * x.c)%MOD;
		res.d = (c * x.b + d * x.d)%MOD;
		return res;
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	while (1) {
		int n; cin >> n;
		if (n == -1) break;
		mat F, E;
		F.a = F.b = F.c = 1;  F.d = 0;
		E.a = E.d = 1; E.b = E.c = 0;
		while (n > 0) {
			if (n % 2) E = E * F;
			F = F * F;
			n /= 2;
		}
		cout << E.c << '\n';
	}
}