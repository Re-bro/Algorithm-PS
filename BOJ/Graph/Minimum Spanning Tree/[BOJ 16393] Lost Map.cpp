/* [BOJ 16393] Lost Map
	Algorithm : Minimum Spanning Tree

	MST 기본 문제
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

int P[3000];
int find(int a) {
	return P[a] < 0 ? a : P[a] = find(P[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (P[a] > P[b]) swap(a, b);
		P[a] += P[b];
		P[b] = a;
		return true;
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	vector<tuple<int, int, int>>edge;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a; cin >> a;
			if (i < j) edge.push_back(make_tuple(a, i, j));
		}
	}
	ini(P, -1);
	sort(all(edge));
	vector<pii> ans;
	for (auto[a, i, j] : edge) {
		if (merge(i, j)) ans.push_back({ i, j });
	}
	for (auto[a, b] : ans) {
		cout << a << ' ' << b << '\n';
	}
}