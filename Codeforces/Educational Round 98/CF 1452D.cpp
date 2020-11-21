/* CF Educational round 98 D
	Algorithm : DP / Number theory

	전체 경우의 수인 y는 2^n이다. 
	그리고 문제 조건을 만족하는 경우의 수는 n = 1, 2, 3,..일때 나열해보면
	피보나치 수열을 이루는 것을 알 수 있다.
	x와 y 각각을 구한 후, 페르마의 소정리를 이용하여 y의 모듈러역원을 구한다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 998244353;
const int MAX = 2e9;
const double PI = acos(-1);

ll dp[200001];
ll mpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b % 2) res = (res*a)%MOD;
		b /= 2;
		a = (a*a) % MOD;
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	ll y = mpow(2, n);
	y = mpow(y, MOD - 2);
	cout << (dp[n] * y) % MOD;
}
