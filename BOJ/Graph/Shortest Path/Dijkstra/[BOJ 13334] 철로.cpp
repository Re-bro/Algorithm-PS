/* [BOJ 13334] ö��
	Algorithm : Sorting / Priority_queue

	�� ������ ������ ö���� ������ ��ġ��Ű�鼭 ö�θ� ���ʿ��� ���������� �̵���Ų��.
	ö�θ� �̵���Ű�鼭 ������ �߰���Ű��, priority_queue���� ������ ���ʳ��� ������������ �����ϵ��� �Ͽ�,
	ö�θ� ��� ������ ������ �� �ֵ��� �Ѵ�.
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