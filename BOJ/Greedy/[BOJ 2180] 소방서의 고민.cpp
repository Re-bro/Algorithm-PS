/* [BOJ 2180] 소방서의 고민
	Algorithm : Greedy / Sort

	....i j .... 가 .... j i .... 보다 더 최적인 경우는 이전까지의 시간을 T라고 하면 
	a[i]*T + b[i] + (a[i]*T + b[i] + T)*a[j] + b[j] < a[j]*T + b[j] + (a[j]*T + b[j] + T)*a[i] + b[i]를 만족한다.
	양변을 소거해주면 b[i]a[j] < a[i]b[j]를 만족하면 된다. 
	즉, b/a가 작은 순서대로 선택해주면 되고, a와 b가 둘 다 0인 경우는 예외처리를 해준다.
	
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