/* [BOJ 20190] 버블버블
	Algorithm : Lazy propagation with Segment tree
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

int A[300001];
int tr[1200001];
int lazy[1200001];
int N;
void update_lazy(int x, int s, int e);
int sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += tr[i];
		i -= (i & -i);
	}
	return ans;
}
void update(int i, int val) {
	while (i <= N) {
		tr[i] += val;
		i += (i & -i);
	}
}
void update_range(int x, int s, int e, int l, int r, int val) {
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
	update_range(x * 2, s, (s + e) / 2, l, r, val);
	update_range(x * 2 + 1, (s + e) / 2 + 1, e, l, r, val);
	tr[x] = min(tr[x * 2], tr[x * 2 + 1]);
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
int min_(int x, int s, int e, int l, int r) {
	update_lazy(x, s, e);
	if (s > r || e < l) return MAX;
	if (s >= l && e <= r) return tr[x];
	else return min(min_(x * 2, s, (s + e) / 2, l, r), min_(x * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N;
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		v.push_back(A[i]);
	}
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	for (int i = 1; i <= N; i++) {
		A[i] = lower_bound(all(v), A[i]) - v.begin() + 1;
	}
	ll bubble = 0;
	for (int i = N; i >= 1; i--) {
		bubble += sum(A[i] - 1);
		update(A[i], 1);
	}

	ini(tr, 0);
	int s = 0;
	int e = N+1;
	for (int i = 1; i <= N; i++) {
		update_range(1, s, e, A[i] + 1, e, 1);
	}
	for (int i = 1; i <= N; i++) {
		update_range(1, s, e, A[i] + 1, e, -1);
		int pre = min_(1, s, e, A[i], A[i]);
		int post = min_(1, s, e, s, e);
		cout << bubble - pre + post << ' ';
		update_range(1, s, e, s, A[i] - 1, 1);
	}
}