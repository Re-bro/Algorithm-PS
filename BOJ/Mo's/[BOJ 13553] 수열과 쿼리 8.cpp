/*
	[BOJ 13553] ¼ö¿­°ú Äõ¸® 8
	Algorithm : Mo's Algorithm / Fenwick Tree
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
#define fi first
#define se second

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);
int n, k;
int a[101010];
int tr[101010];
void update(int i, int val) {
	while (i <= 100000) {
		tr[i] += val;
		i += (i & -i);
	}
}
int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += tr[i];
		i -= (i&-i);
	}
	return res;
}
struct query {
	int l, r, idx;
	bool operator < (query q) {
		if (r / 400 == q.r / 400) return l < q.l;
		else return r / 400 < q.r / 400;
	}
};
query q[101010];
ll ans = 0;
ll res[101010];
void add(int s) {
	ans += sum(min(a[s] + k, 100000)) - sum(max(0, a[s] - k - 1));
	update(a[s], 1);
}
void sub(int s) {
	ans -= sum(min(a[s] + k, 100000)) - sum(max(0, a[s] - k - 1)) - 1;
	update(a[s], -1);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int m; cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].idx = i;
	}
	sort(q + 1, q + 1 + m);
	int l = 1, r = 0;
	
	for (int i = 1; i <= m; i++) {
		while (l > q[i].l) add(--l);
		while (l < q[i].l) sub(l++);
		while (r > q[i].r) sub(r--);
		while (r < q[i].r) add(++r);
		res[q[i].idx] = ans;
	}
	for (int i = 1; i <= m; i++) cout << res[i] << '\n';
}