/* Round #686 (Div. 3) D
	Algorithm : math

	n�� �־�����, ���Ҹ� ��� ���ϸ� n�� �ǰ�, 
	A[i] % A[i-1] == 0 �� ��� �����ؾ� �ϵ��� �ϴ� �ִ� ���� ������ ���ϴ� �����̴�.
	n�� ���μ����� ���� ��, ���� ���� ������ �Ҽ��� p��� �ϸ�
	p, p, p, ...., p, p*d (d�� n�� p�� ���̻� ������ �������� ���� �� ���� ���� ��) �� ���ϸ� �ȴ�.
	
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