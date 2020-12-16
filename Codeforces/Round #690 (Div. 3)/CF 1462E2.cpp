/* [CF 1462E2] Close Tuples (hard version)
	Algorithm : sorting / binary search / combinatorics

	�켱 �迭�� ������������ �����صΰ�, i = 1 ~ n-m+1 �� ���ؼ� A[i]�� �ּڰ��� ��츦 �����Ѵ�.
	A[i]�� �ּڰ��̱� ������ ������ m-1���� ���Ҵ� i+1 ~ n�� �������� �̾����� �Ѵ�.
	�� ��, ������ ���Ҵ� A[i] + k ���Ͽ����ϹǷ�, A[i] + k ������ ������ index�� �ִ��� lower_bound�� ���� ��,
	������ ���ҵ� �� m-1���� �̴� ����� ���� ���Ѵ�.
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;
const double PI = acos(-1);
int A[200001];
#define MAX_C 200000
ll fac[MAX_C + 1], facinv[MAX_C + 1];
ll mpow(ll a, ll x) { //a^x
	ll res = 1;
	while (x > 0) {
		if (x % 2) res *= a;
		res %= MOD;
		a = (a*a) % MOD;
		x /= 2;
	}
	return res;
}

ll combi(ll n, ll r) {
	return (((fac[n] * facinv[r]) % MOD)*facinv[n - r]) % MOD;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	fac[0] = 1;
	for (int i = 1; i <= MAX_C; i++) fac[i] = (fac[i - 1] * i) % MOD;
	facinv[MAX_C] = mpow(fac[MAX_C], MOD - 2);
	for (int i = MAX_C - 1; i >= 0; i--) facinv[i] = facinv[i + 1] * (i + 1) % MOD;

	while (T--) {
		int n, m, k; cin >> n >> m >> k;
		vector<int> cnt(2 * n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			cnt[A[i]]++;
		}
		sort(A + 1, A + 1 + n);
		ll ans = 0;
		for (int i = 1; i <= n - m + 1; i++) {
			int k1 = lower_bound(A + 1, A + 1 + n, A[i] + k) - A;
			k1 += cnt[A[i] + k] - 1;
			if (k1 - i + 1 >= m) ans += combi(k1 - i, m - 1);
			ans %= MOD;
		}
		cout << ans << '\n';
	}
}