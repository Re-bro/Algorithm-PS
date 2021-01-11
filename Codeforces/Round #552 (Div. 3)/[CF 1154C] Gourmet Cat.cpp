/* [CF 1154C] Gourmet Cat
	Algorithm : Math

	월/목/일요일에는 fish를, 화/토요일에는 rabbit을, 수/금요일에는 chicken을 먹고,
	fish는 a개, rabbit은 b개, chicken은 c개 있을 때, 가장 오래 먹을 수 있도록 요일을 고르는 문제이다.
	어떤 요일부터 시작하든, 항상 7일동안은 fish를 3개, rabbit과 chicken을 2개씩 먹는다.
	따라서 최소 min(a/3, b/2, c/2) * 7일 만큼은 먹을 수 있고, 나머지를 가지고 얼마나 더 먹을 수 있는지 확인한다.
	a, b, c중 적어도 하나는 1이하의 값이 되므로 직접 다 돌려보면 된다.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int A[7] = { 1, 2, 3, 1, 3, 2, 1 };
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll a, b, c; cin >> a >> b >> c;
	ll ans = 0;
	ll k = min({ a / 3, b / 2, c / 2 });
	a -= k * 3;
	b -= k * 2;
	c -= k * 2;
	for (int i = 0; i < 7; i++) {
		ll ta = a;
		ll tb = b;
		ll tc = c;
		ll cnt = 0;
		for (int j = i; ; j++) {
			if (A[j % 7] == 1) {
				if (ta == 0) break;
				else cnt++, ta--;
			}
			else if (A[j % 7] == 2) {
				if (tb == 0) break;
				else cnt++, tb--;
			}
			else {
				if (tc == 0) break;
				else cnt++, tc--;
			}
		}
		ans = max(ans, k * 7 + cnt);
	}
	cout << ans;
}