/* [BOJ 18877] Social Distancing
	Algorithm : Parametric Search
	
	�� �� ������ �Ÿ��� ���������� ��, �Ұ� N���� �̻� ��ġ�� �����ϸ�
	�Ÿ��� �� ������ �ǰ�, N�������� ������ �Ÿ��� �� �ٿ��� �Ѵ�. 
	���� �� ������ �̺�Ž���� ���ؼ� ������ D�� ã���ش�. 
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
vector<pll> v;
int N, M;
bool sol(ll a) {
	ll cnt = 0;
	ll last = -(ll)1e18;
	for (int i = 0; i < sz(v); i++) {
		if (last + a <= v[i].first) {
			cnt += (v[i].second - v[i].first) / a +1;
			last = v[i].first + ((v[i].second - v[i].first) / a) * a;
		}
		else if (last + a <= v[i].second) {
			ll k = (v[i].second - (last + a)) / a;
			cnt += k + 1;
			last += (k+1) * a;
		}
		if (cnt >= N) return true;
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		ll a, b; cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(all(v));
	ll s = 1;
	ll e = (ll)1e18;
	ll ans = 1;
	while (s <= e) {
		ll mid = (s + e) / 2;
		if (sol(mid)) {
			ans = max(ans, mid);
			s = mid + 1;
		}
		else e = mid-1;
	}
	cout << ans;
}