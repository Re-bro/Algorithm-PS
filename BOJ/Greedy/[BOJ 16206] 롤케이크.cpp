/* [BOJ 16206] 롤케이크
	Algorithm : Greedy

	10의 배수이면서 작은 롤케이크부터 자르는것이 최적이다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<int>v1, v2;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (a % 10) v2.push_back(a);
		else v1.push_back(a);
	}
	sort(all(v1));
	int ans = 0;
	for (int i = 0; i < sz(v1); i++) {
		if (v1[i] / 10 - 1 <= m) {
			ans += v1[i] / 10;
			m -= v1[i] / 10 - 1;
		}
		else {
			ans += m;
			m = 0;
		}
	}
	for (int i = 0; i < sz(v2); i++) {
		ans += min(m, v2[i] / 10);
		m -= min(m, v2[i] / 10);
	}
	cout << ans;
}