/* [BOJ 5552] 걷는 산타클로스
	Algorithm : Sorting

	x좌표와  y좌표를 따로 생각해도 된다. 
	집들의 x좌표와 y좌표를 각각 정렬했을 때, 루돌프가 있는 교차로의 x좌표와 y좌표는 각각 중간에 위치하는게 최적이다.
	그리고 마지막에 방문하는 경우에는 다시 돌아오지 않으므로 가장 멀리 있는 점을 마지막에 방문한다. 
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