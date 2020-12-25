/* [BOJ 18265] MooBuzz
	Algorithm : Binary Search

	k���� �� ��, ���ڰ� ������ ������ 3�� ����� 5�� ����� ������ �����̴�. 
	��, k - k/3 - k/5 + k/15�� ���ڰ� ������ �����̴�. 
	���� �� ���� N���� ũ�ٸ� k�� �ٿ���� �ϰ�, N���� �۴ٸ� k�� Ű����� �Ѵ�.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll N; cin >> N;
	ll s = 1;
	ll e = (ll)1e18;
	ll ans = (ll)1e18;
	while (s <= e) {
		ll mid = (s + e) / 2;
		ll k = mid - mid / 3 - mid / 5 + mid / 15;
		if (k >= N) {
			if(k == N) ans = min(ans, mid);
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << ans;
}