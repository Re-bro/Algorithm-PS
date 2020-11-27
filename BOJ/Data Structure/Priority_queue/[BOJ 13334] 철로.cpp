/* [BOJ 13334] 철로
	Algorithm : Sorting / Priority_queue

	각 선분의 끝점과 철로의 끝점을 일치시키면서 철로를 왼쪽에서 오른쪽으로 이동시킨다.
	철로를 이동시키면서 선분을 추가시키고, priority_queue에는 선분의 왼쪽끝을 오름차순으로 정렬하도록 하여,
	철로를 벗어난 선분은 제거할 수 있도록 한다.
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

bool cmp(pii a, pii b) {
	return a.second < b.second;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	vector<pii> v;
	for (int i = 1; i <= n; i++) {
		int h, o; cin >> h >> o;
		if (h > o) swap(h, o);
		v.push_back({ h, o });
	}
	int ans = 0;
	int d; cin >> d;
	sort(all(v), cmp);
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		while (1) {
			if (!pq.empty() && pq.top() < v[i].second - d) pq.pop();
			else break;
		}
		if (v[i].second - v[i].first <= d) pq.push(v[i].first);
		ans = max(ans, sz(pq));
	}
	cout << ans;
}