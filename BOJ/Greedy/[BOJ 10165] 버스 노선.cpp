/* [BOJ 10165] 버스 노선
	Algorithm : Greedy / Sorting

	a > b인 노선인 경우에는 b에 +n을 해주어서 원을 일자형태로 풀이할 수 있게 만든다.
	단, b+n을 했을 때, 문제 예시에서의 5번이 1번을 포함하는 것을 고려하지 못한다.
	이런 경우는 버스 노선 중 가장 긴 노선의 시작지점이 0이 되도록 각 버스노선들의 위치를 같이 조정해주면
	가장 긴 노선은 항상 다른 노선에 포함될 수 없으므로, 자연스럽게 위의 예외들이 생기지 않는다. 

	어떤 노선 x가 노선 y에 포함된다면 x.a >= y.a && x.b <=y.b를 만족해야하므로 
	스위핑을 통해서 풀어준다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using pii = pair<int, int>;
bool cmp(tuple<int, int, int> x, tuple<int, int, int> y) {
	auto [a, b, c] = x;
	auto [d, e, f] = y;
	if (b == e) return a > d;
	else return b < e;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<tuple<int, int, int>>v;
	int mx = 0;
	int s;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		v.push_back(make_tuple(a, b, i));
		if (a > b) {
			if (mx < b + n - a) {
				mx = b + n - a;
				s = a;
			}
		}
		else {
			if (mx < b - a) {
				mx = b - a;
				s = a;
			}
		}
	}
	for (auto& [a, b, c] : v) {
		a = (a + n - s) % n;
		b = (b + n - s) % n;
		if (a > b) b += n;
	}
	sort(all(v), cmp);
	priority_queue<pii> pq;
	for (auto [a, b, c] : v) {
		while (!pq.empty() && pq.top().first >= a) pq.pop();
		pq.push({ a, c });
	}
	vector<int> ans;
	while (!pq.empty()) {
		ans.push_back(pq.top().second);
		pq.pop();
	}
	sort(all(ans));
	for (int i : ans) cout << i << ' ';
}