/* [CF 1471A] Strange Partition
	Algorithm : math / Implementation

	최대인 경우는 연산을 한번도 하지 않은 원래의 배열에서 합을 구해주는 경우이고, 
	최소인 경우는 연산을 n-1번 적용한, 즉 배열의 원소가 1개만 남았을 때이다. 
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		ll n, x; cin >> n >> x;
		ll mi = 0, mx = 0;
		for (int i = 1; i <= n; i++) {
			ll a; cin >> a;
			mi += a;
			mx += (a + x - 1) / x;
		}
		cout << (mi + x - 1) / x << ' ' << mx << '\n';
	}
}