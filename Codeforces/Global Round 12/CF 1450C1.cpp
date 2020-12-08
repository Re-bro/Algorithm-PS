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

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<string> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		int c1 = 0, c2 = 0, c3 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] == 'X') {
					if ((i + j) % 3 == 0) c1++;
					else if ((i + j) % 3 == 1) c2++;
					else if ((i + j) % 3 == 2) c3++;
				}
			}
		}
		int k;
		if (c1 <= c2 && c1 <= c3) k = 0;
		else if (c2 <= c1 && c2 <= c3) k = 1;
		else k = 2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] == 'X' && (i + j) % 3 == k) v[i][j] = 'O';
			}
		}
		for (int i = 0; i < n; i++) cout << v[i] << '\n';
	}
}