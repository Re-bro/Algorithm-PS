/* [CF 1471B] Strange List
	Algorithm : math

	����, x�� ������ ������ �� �迭�� �߰��Ǵ� ������ ���� ���� �迭�� ���ҿ� ������ ���� �� �� �ִ�.
	�׸��� ���� ó�� x�� ������ �������� �ʴ� ���� ���������� üũ�Ѵ�.
	x�� ������ �������� ���� ������ ���� �� �ִ� Ƚ���� ���� ���� ������ �ε����� k��� �ϰ�,
	A[k]�� ���� �� �ִ� Ƚ���� cnt��� �ϸ� A[1] ~ A[k-1] ������ cnt+1�� ���� �� �ְ�, A[k] ~ A[n] ������ cnt�� ���� �� �ִ�.
	A[k]�� cnt�� ������ �Ǹ� x�� ���̻� ������ �������� �ʰ� �ǰ�, ���� ������ ����Ǳ� �����̴�.
	���� A[1] ~ A[n]�� ���� cnt�� ���ϰ�, A[1] ~ A[k-1]�� ���� �� �����ָ� �ȴ�.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int A[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		ll n, x; cin >> n >> x;
		ll sum = 0;
		ll cnt = 1000;
		ll k;
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			sum += A[i];
			ll a = A[i];
			ll c = 0;
			while (1) {
				if (a%x == 0) {
					a /= x;
					c++;
				}
				else {
					if (cnt > c) {
						cnt = c;
						k = i;
					}
					break;
				}
			}
		}
		ll ans = sum*(cnt + 1);
		for (int i = 1; i < k; i++) {
			ans += A[i];
		}
		cout << ans << '\n';
	}
}