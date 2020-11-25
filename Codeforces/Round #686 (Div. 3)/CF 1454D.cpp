/* Round #686 (Div. 3) D
	Algorithm : math

	n이 주어지면, 원소를 모두 곱하면 n이 되고, 
	A[i] % A[i-1] == 0 을 모두 만족해야 하도록 하는 최대 길이 수열을 구하는 문제이다.
	n을 소인수분해 했을 때, 가장 많이 나오는 소수를 p라고 하면
	p, p, p, ...., p, p*d (d는 n을 p로 더이상 나누어 떨어지지 않을 때 까지 나눈 수) 로 구하면 된다.
	
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
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);

ll prime[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	vector<ll> P;
	for (int i = 2; i <= 100000; i++) {
		if (prime[i] == 0) {
			P.push_back(i);
			for (int j = 2; j*i <= 100000; j++) {
				prime[i*j] = 1;
			}
		}
	}
	int psz = sz(P);
	while (T--) {
		ll n; cin >> n;
		ll k = n;
		int idx = 0;
		int cnt = 0;
		ll ans = 1;
		ll val = 0;
		while (k > 1 && idx < sz(P)) {
			if (k%P[idx] == 0) {
				cnt++;
				k /= P[idx];
			}
			else {
				if (cnt > ans) {
					ans = cnt;
					val = P[idx];
				}
				cnt = 0;
				idx++;
			}
		}
		if (cnt > ans) {
			ans = cnt;
			val = P[idx];
		}
		if (ans == 1) {
			cout << 1 << '\n' << n << '\n';
		}
		else {
			cout << ans << '\n';
			for (int i = 1; i < ans; i++) {
				cout << val << ' ';
				n /= val;
			}
			cout << n << '\n';
		}
	}
}