/* CF Educational round 98 D
	Algorithm : DP / Number theory

	��ü ����� ���� y�� 2^n�̴�. 
	�׸��� ���� ������ �����ϴ� ����� ���� n = 1, 2, 3,..�϶� �����غ���
	�Ǻ���ġ ������ �̷�� ���� �� �� �ִ�.
	x�� y ������ ���� ��, �丣���� �������� �̿��Ͽ� y�� ��ⷯ������ ���Ѵ�.
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
