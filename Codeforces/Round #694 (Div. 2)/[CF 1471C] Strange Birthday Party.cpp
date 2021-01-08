/* [CF 1471C] Strange Birthday Party
	Algorithm : Greedy / Sorting

	먼저 친구들의 번호를 오름차순으로 정렬한다.
	상품의 가격들이 오름차순으로 주어지기 때문에 돈으로 지불한다면 친구의 번호가 클수록 비용이 많이 든다.
	그러므로 번호가 큰 친구들부터 차례대로 싼 상품들을 선물하는게 최적이다.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll k[300001];
ll c[300001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		ll n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> k[i];
		for (int i = 1; i <= m; i++) cin >> c[i];
		sort(k + 1, k + n + 1);
		ll left = 1;
		ll ans = 0;
		for (int i = n; i >= 1; i--) {
			if (left > k[i]) ans += c[k[i]];
			else ans += c[left++];
		}
		cout << ans << '\n';
	}
}