/*
	[BOJ 17076] 망가진 데이터
	Algorithm : Segment Tree
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

int a[202020];
int mx[202020];
int tr[808080];
int find(int x, int s, int e, int cnt) {
	if (s == e) return s;
	if (tr[x * 2] >= cnt) return find(x * 2, s, (s + e) / 2, cnt);
	else return find(x * 2 + 1, (s + e) / 2 + 1, e, cnt - tr[x * 2]);
}
void update(int x, int s, int e, int i, int val) {
	if (i > e || i < s) return;
	tr[x]++;
	if (s != e) {
		update(x * 2, s, (s + e) / 2, i, val);
		update(x * 2 + 1, (s + e) / 2 + 1, e, i, val);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int k; cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		mx[i] = max(mx[i - 1], a[i]);
	}
	int N = 0, M = 0;
	for (int i = k; i > 1; i--) {
		int res = find(1, 1, 200001, a[i] * 2);
		if (mx[i-1] >= res) {
			if (N < mx[i] || (N == mx[i] && M < a[i])) {
				N = mx[i];
				M = a[i];
			}
		}
		update(1, 1, 200001, a[i], 1);
	}
	if (N == 0) cout << -1;
	else cout << N << ' ' << M;
}