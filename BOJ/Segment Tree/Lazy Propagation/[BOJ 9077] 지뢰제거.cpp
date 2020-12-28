/* [BOJ 9077] 지뢰제거
	Algorithm : Lazy propagation with segment tree
	
	지뢰의 좌표를 (x, y)라고 하면, 정사각형의 중심의 y좌표가 [y-5, y+5] 구간 사이에 있는 경우
	지뢰를 제거할 수 있다.
	따라서 x좌표 기준으로 정렬한 뒤, 각 지뢰별로 [y`5, y+5] 구간에 lazy propagation을 이용하여 1씩 더해준다. 
	그러면 최댓값 세그먼트 트리를 이용해서 구간 전체에서의 최댓값을 구하면 제거할 수 있는 최대 지뢰의 수가 나온다. 
	현재 지뢰의 x좌표보다 10m 넘게 차이나는 지뢰들은 deque을 이용해서 계속해서 제거해준다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);

int tr[50000];
int lazy[50001];
int N;
void update_lazy(int x, int s, int e);
void update(int x, int s, int e, int l, int r, int val) {
	update_lazy(x, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r) {
		tr[x] += val;
		if (s != e) {
			lazy[x * 2] += val;
			lazy[x * 2 + 1] += val;
		}
		return;
	}
	update(x * 2, s, (s + e) / 2, l, r, val);
	update(x * 2 + 1, (s + e) / 2 + 1, e, l, r, val);
	tr[x] = max(tr[x * 2], tr[x * 2 + 1]);
}
void update_lazy(int x, int s, int e) {
	if (lazy[x] != 0) {
		tr[x] += lazy[x];
		if (s != e) {
			lazy[x * 2] += lazy[x];
			lazy[x * 2 + 1] += lazy[x];
		}
		lazy[x] = 0;
	}
}
int query(int x, int s, int e, int l, int r) {
	update_lazy(x, s, e);
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tr[x];
	else return max(query(x * 2, s, (s + e) / 2, l, r), query(x * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		ini(tr, 0); ini(lazy, 0);
		vector<pii> v;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			int x, y; cin >> x >> y;
			x += 10; y += 10;
			v.push_back({ x, y });
		}
		sort(all(v));
		deque<pii> dq;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			while (!dq.empty()) {
				if (dq.front().first < v[i].first - 10) {
					update(1, 1, 11000, dq.front().second - 5, dq.front().second + 5, -1);
					dq.pop_front();
				}
				else break;
			}
			update(1, 1, 11000, v[i].second - 5, v[i].second + 5, 1);
			dq.push_back(v[i]);
			ans = max(ans, query(1, 1, 11000, 1, 11000));
		}
		cout << ans << '\n';
	}

}