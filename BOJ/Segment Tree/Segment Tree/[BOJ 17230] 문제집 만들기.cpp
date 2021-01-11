/* [BOJ 17230] 문제집 만들기
	Algorithm : Segment Tree

	각 문제별로 먼저 풀어야 하는 문제들을 set으로 관리한다.
	그 set 안에서 최솟값과 최댓값을 각각 최소 세그트리, 최대 세그트리에 저장한다.
	그리고, x에서 y까지 문제를 모두 풀 수 있는 경우는, 
	먼저 풀어야 하는 문제들 중 x보다 작거나 y보다 큰 문제가 존재하지 않는 경우이다.
	즉, 최소 세그트리에서의 [x, y] 값과 최대 세그트리에서의 [x, y]값이 
	x이상 y이하의 범위에 포함되어야 한다. 

	update하는 경우에는 set을 이용하여 추가, 삭제를 해주고, begin(), rbegin()을 이용하여
	set에서의 최솟값, 최댓값을 구한다.
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;

int P[100001];
set<int> st[100001];
int mi_tr[400001];
int mx_tr[400001];
int init(int x, int s, int e, bool mi) {
	if (s == e) {
		if (mi) return mi_tr[x] = *(st[s].begin());
		else return mx_tr[x] = *(st[s].rbegin());
	}
	if(mi) return mi_tr[x] = min(init(x * 2, s, (s + e) / 2, mi), init(x * 2 + 1, (s + e) / 2 + 1, e, mi));
	else return mx_tr[x] = max(init(x * 2, s, (s + e) / 2, mi), init(x * 2 + 1, (s + e) / 2 + 1, e, mi));
}
int query(int x, int s, int e, int l, int r, bool mi) {
	if (s > r || e < l) {
		if (mi) return MAX;
		else return 0;
	}
	if (s >= l && e <= r) {
		if (mi) return mi_tr[x];
		else return mx_tr[x];
	}
	if (mi) return min(query(x * 2, s, (s + e) / 2, l, r, mi), query(x * 2 + 1, (s + e) / 2 + 1, e, l, r, mi));
	else return max(query(x * 2, s, (s + e) / 2, l, r, mi), query(x * 2 + 1, (s + e) / 2 + 1, e, l, r, mi));
}
int update(int x, int s, int e, int i, int val, bool mi) {
	if (i > e || i < s) {
		if (mi) return mi_tr[x];
		else return mx_tr[x];
	}
	if (s == e) {
		if (mi) return mi_tr[x] = val;
		else return mx_tr[x] = val;
	}
	if (mi) return mi_tr[x] = min(update(x * 2, s, (s + e) / 2, i, val, mi), update(x * 2 + 1, (s + e) / 2 + 1, e, i, val, mi));
	else return mx_tr[x] = max(update(x * 2, s, (s + e) / 2, i, val, mi), update(x * 2 + 1, (s + e) / 2 + 1, e, i, val, mi));
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M, Q; cin >> N >> M >> Q;
	for (int i = 1; i <= M; i++) {
		int a, b; cin >> a >> b;
		st[a].insert(b);
	}
	for (int i = 1; i <= N; i++) st[i].insert(i);
	init(1, 1, N, true);
	init(1, 1, N, false);
	for (int i = 1; i <= Q; i++) {
		int a, x, y; cin >> a >> x >> y;
		if (a == 1) {
			int mi = query(1, 1, N, x, y, true);
			int mx = query(1, 1, N, x, y, false);
			if (mi < x || mx > y) cout << "NO\n";
			else cout << "YES\n";
		}
		else {
			if (a == 2) st[x].erase(y);
			else st[x].insert(y);
			update(1, 1, N, x, *(st[x].begin()), true);
			update(1, 1, N, x, *(st[x].rbegin()), false);
		}
	}
}