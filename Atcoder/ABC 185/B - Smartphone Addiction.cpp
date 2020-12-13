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


int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N, M, T; cin >> N >> M >> T;
	int last = 0;
	bool chk = true;
	int ori = N;
	for (int i = 1; i <= M; i++) {
		int a, b; cin >> a >> b;
		N -= (a - last);

		if (N <= 0) chk = false;
		N += b - a;

		N = min(N, ori);
		last = b;
	}
	N -= (T - last);
	if (N <= 0) chk = false;
	if (chk) cout << "Yes";
	else cout << "No";
}