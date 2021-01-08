/* [BOJ 18881] Social Distancing II
	Algorithm : sorting

	소의 위치별로 정렬해두고, 감염되지 않은 소로부터 감염된 소가 위치한
	최소 거리보다 R이 작아야 한다. 
	R을 구하고 나서, R범위로 묶이는 감염된 소의 그룹의 수를 구하면 된다.
*/

#include<bits/stdc++.h>	
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	vector<pii> v;
	for (int i = 1; i <= N; i++) {
		int x, s; cin >> x >> s;
		v.push_back({ x, s });
	}
	sort(all(v));
	int dis = MAX;
	for (int i = 0; i < sz(v); i++) {
		if (v[i].second == 0) {
			if (i > 0 && v[i - 1].second == 1) dis = min(dis, v[i].first - v[i - 1].first);
			if (i < sz(v) - 1 && v[i + 1].second == 1) dis = min(dis, v[i + 1].first - v[i].first);
		}
	}
	int ans = 0;
	int last = -1;
	for (int i = 0; i < sz(v); i++) {
		if (v[i].second == 1) {
			if (last == -1) {
				ans++;
			}
			else if (v[i].first - last >= dis) {
				ans++;
			}
			last = v[i].first;
		}
	}
	cout << ans;
}