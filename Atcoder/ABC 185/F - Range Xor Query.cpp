#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);

int A[300001];
int tr[1200001];
int init(int x, int s, int e) {
	if (s == e) return tr[x] = A[s];
	return tr[x] = init(x * 2, s, (s + e) / 2) ^ init(x * 2 + 1, (s + e) / 2 + 1, e);
}
int update(int x, int s, int e, int i, int val) {
	if (i < s || i > e) return tr[x];
	if (s == e) return tr[x] ^= val;
	else {
		return tr[x] = update(x * 2, s, (s + e) / 2, i, val) ^ update(x * 2 + 1, (s + e) / 2 + 1, e, i, val);
	}
}
int sum(int x, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tr[x];
	else return sum(x * 2, s, (s + e) / 2, l, r) ^ sum(x * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N, Q; cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> A[i];
	init(1, 1, N);
	for (int i = 1; i <= Q; i++) {
		int t, x, y; cin >> t >> x >> y;
		if (t == 1) {
			update(1, 1, N, x, y);
		}
		else {
			cout << sum(1, 1, N, x, y) << '\n';
		}
	}
}