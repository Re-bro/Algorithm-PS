/*
	[BOJ 1657] 두부장수 장홍준
	Algorithm : Bit DP
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

int n, m; 
vector<string> v(15);
int dp[14][14][1 << 14];
int s[6][6] = { {10, 8, 7, 5, 0, 1}, {8, 6, 4, 3, 0, 1}, {7, 4, 3, 2, 0, 1}, {5, 3, 2, 2, 0, 1}, {0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0} };
int sol(int x, int y, int bit) {
	if (x == n) {
		return 0;
	}
	int &ret = dp[x][y][bit];
	if (ret != -1) return ret;
	ret = 0;
	if (bit & 1) {
		if (y == m - 1) ret = max(ret, sol(x + 1, 0, bit >> 1));
		else ret = max(ret, sol(x, y + 1, bit >> 1));
	}
	else {
		if ((bit & 3) == 0 && y < m - 1) {
			ret = max(ret, sol(x, y + 1, (bit >> 1) | 1) + s[v[x][y] - 'A'][v[x][y + 1] - 'A']);
		}
		if (x < n - 1) {
			if (y == m - 1) ret = max(ret, sol(x + 1, 0, (bit >> 1) | (1 << (m - 1))) + s[v[x][y] - 'A'][v[x + 1][y] - 'A']);
			else ret = max(ret, sol(x, y + 1, (bit >> 1) | (1 << (m - 1))) + s[v[x][y] - 'A'][v[x + 1][y] - 'A']);
		}
		if (y == m - 1) ret = max(ret, sol(x + 1, 0, bit >> 1));
		else ret = max(ret, sol(x, y + 1, bit >> 1));
	}
	
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> v[i];
	ini(dp, -1);
	cout << sol(0, 0, 0);
}