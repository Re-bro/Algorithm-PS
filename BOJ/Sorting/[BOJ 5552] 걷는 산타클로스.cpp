/* [BOJ 5552] �ȴ� ��ŸŬ�ν�
	Algorithm : Sorting

	x��ǥ��  y��ǥ�� ���� �����ص� �ȴ�. 
	������ x��ǥ�� y��ǥ�� ���� �������� ��, �絹���� �ִ� �������� x��ǥ�� y��ǥ�� ���� �߰��� ��ġ�ϴ°� �����̴�.
	�׸��� �������� �湮�ϴ� ��쿡�� �ٽ� ���ƿ��� �����Ƿ� ���� �ָ� �ִ� ���� �������� �湮�Ѵ�. 
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll w, h; cin >> w >> h;
	int n; cin >> n;
	vector<int> x, y;
	vector<pii> v;
	for (int i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
		v.push_back({ a, b });
	}
	sort(all(x)); sort(all(y));
	vector<int> px, py;
	px.push_back(x[(n - 1) / 2]); px.push_back(x[n / 2]);
	py.push_back(y[(n - 1) / 2]); py.push_back(y[n / 2]);
	ll ans = 1e18;
	ll rx, ry;
	for (int nx : px) {
		for (int ny : py) {
			ll tmp = 0;
			ll mx = 0;
			for (int i = 0; i < n; i++) {
				ll k = abs(v[i].first - nx) + abs(v[i].second - ny);
				tmp += k;
				mx = max(mx, k);
			}
			tmp *= 2;
			tmp -= mx;
			if (tmp < ans) ans = tmp, rx = nx, ry = ny;
		}
	}
	cout << ans << '\n';
	cout << rx << ' ' << ry;
}