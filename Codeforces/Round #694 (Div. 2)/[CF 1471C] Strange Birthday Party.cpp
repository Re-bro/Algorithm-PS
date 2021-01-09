/* [CF 1471C] Strange Birthday Party
	Algorithm : Greedy / Sorting

	���� ģ������ ��ȣ�� ������������ �����Ѵ�.
	��ǰ�� ���ݵ��� ������������ �־����� ������ ������ �����Ѵٸ� ģ���� ��ȣ�� Ŭ���� ����� ���� ���.
	�׷��Ƿ� ��ȣ�� ū ģ������� ���ʴ�� �� ��ǰ���� �����ϴ°� �����̴�.
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