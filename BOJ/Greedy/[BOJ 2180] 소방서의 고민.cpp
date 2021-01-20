/* [BOJ 2180] �ҹ漭�� ���
	Algorithm : Greedy / Sort

	....i j .... �� .... j i .... ���� �� ������ ���� ���������� �ð��� T��� �ϸ� 
	a[i]*T + b[i] + (a[i]*T + b[i] + T)*a[j] + b[j] < a[j]*T + b[j] + (a[j]*T + b[j] + T)*a[i] + b[i]�� �����Ѵ�.
	�纯�� �Ұ����ָ� b[i]a[j] < a[i]b[j]�� �����ϸ� �ȴ�. 
	��, b/a�� ���� ������� �������ָ� �ǰ�, a�� b�� �� �� 0�� ���� ����ó���� ���ش�.
	
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

bool cmp(pll a, pll b) {
	return a.second*b.first < a.first*b.second;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<pll> v;
	for (int i = 1; i <= n; i++) {
		ll a, b; cin >> a >> b;
		if (a == 0 && b == 0) continue;
		v.push_back({ a, b });
	}
	sort(all(v), cmp);
	ll ans = 0;
	for (int i = 0; i < sz(v); i++) {
		ans += v[i].first*ans + v[i].second;
		ans %= 40000;
	}
	cout << ans;
}