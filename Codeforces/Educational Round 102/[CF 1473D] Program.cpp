/* [CF 1473D] Program
	Algorithm : Prefix Sum / Segment Tree

	일단 만들어지는 x값의 가짓수는 연산과정에서의 x의 최솟값과 최댓값을 구하면 된다.
	1 또는 -1이 더해지므로 최솟값과 최댓값 사이에 만들어질 수 없는 값은 존재하지 않는다.
	[l, r] 쿼리가 주어지면, 먼저 l-1번째까지의 최솟값과 최댓값을 구한다.
	그리고 [l, r] 쿼리를 고려하지 않았을 때의 r번째 값과 [r+1, n]에서의 최솟값과 최댓값을 각각 구한 후,
	[r+1, n]에서 값이 얼마만큼 변하는지를 확인한다.
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
using pii = pair<int, int>;
const int MAX = (int)2e9;
int A[200001];
pii range[200001];
int mi_tr[800001];
int mx_tr[800001];
int init(int x, int s, int e, bool mi) {
	if (s == e) {
		if (mi) return mi_tr[x] = A[s];
		else return mx_tr[x] = A[s];
	}
	if (mi) return mi_tr[x] = min(init(x * 2, s, (s + e) / 2, mi), init(x * 2 + 1, (s + e) / 2 + 1, e, mi));
	else return mx_tr[x] = max(init(x * 2, s, (s + e) / 2, mi), init(x * 2 + 1, (s + e) / 2 + 1, e, mi));
}
int query(int x, int s, int e, int l, int r, bool mi) {
	if (s > r || e < l) {
		if (mi) return MAX;
		else return -MAX;
	}
	if (s >= l && e <= r) {
		if (mi) return mi_tr[x];
		else return mx_tr[x];
	}
	if (mi) return min(query(x * 2, s, (s + e) / 2, l, r, mi), query(x * 2 + 1, (s + e) / 2 + 1, e, l, r, mi));
	else return max(query(x * 2, s, (s + e) / 2, l, r, mi), query(x * 2 + 1, (s + e) / 2 + 1, e, l, r, mi));
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			range[i].first = 0;
			range[i].second = 0;
		}
		for (int i = 1; i <= 4 * n; i++) {
			mi_tr[i] = 0;
			mx_tr[i] = 0;
		}
		string s; cin >> s;
		for (int i = 0; i < sz(s); i++) {
			if (s[i] == '+') A[i + 1] = 1;
			else A[i + 1] = -1;
		}
		for (int i = 1; i <= n; i++) {
			A[i] += A[i - 1];
			range[i].first = min(range[i - 1].first, A[i]);
			range[i].second = max(range[i - 1].second, A[i]);
		}
		init(1, 1, n, false); init(1, 1, n, true);
		for (int i = 1; i <= m; i++) {
			int l, r; cin >> l >> r;
			if (r == n) {
				cout << range[l - 1].second - range[l - 1].first + 1 << '\n';
				continue;
			}
			int mi = query(1, 1, n, r + 1, n, true);
			int mx = query(1, 1, n, r + 1, n, false);
			int now = A[l - 1];
			int R = now + mx - A[r];
			int L = now - (A[r] - mi);
			cout << max(R, range[l - 1].second) - min(L, range[l - 1].first) + 1 << '\n';
		}
	}
}