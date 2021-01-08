/* [CF 1471B] Strange List
	Algorithm : math

	먼저, x로 나누어 떨어질 때 배열에 추가되는 원소의 합은 원래 배열의 원소와 동일한 것을 알 수 있다.
	그리고 언제 처음 x로 나누어 떨어지지 않는 수가 나오는지를 체크한다.
	x로 나누어 떨어지지 않을 때까지 나눌 수 있는 횟수가 가장 작은 원소의 인덱스를 k라고 하고,
	A[k]의 나눌 수 있는 횟수를 cnt라고 하면 A[1] ~ A[k-1] 까지는 cnt+1번 나눌 수 있고, A[k] ~ A[n] 까지는 cnt번 나눌 수 있다.
	A[k]를 cnt번 나누게 되면 x로 더이상 나누어 떨어지지 않게 되고, 따라서 수행이 종료되기 때문이다.
	따라서 A[1] ~ A[n]의 합을 cnt번 더하고, A[1] ~ A[k-1]의 합을 더 더해주면 된다.
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