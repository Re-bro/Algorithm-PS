/* [BOJ 18877] Social Distancing
	Algorithm : Parametric Search
	
	각 소 사이의 거리를 고정시켰을 때, 소가 N마리 이상 배치가 가능하면
	거리를 더 넓혀도 되고, N마리보다 적으면 거리를 더 줄여야 한다. 
	따라서 이 과정을 이분탐색을 통해서 적절한 D를 찾아준다. 
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