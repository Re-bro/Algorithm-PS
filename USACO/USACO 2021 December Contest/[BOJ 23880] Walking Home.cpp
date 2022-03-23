#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;

int a[55][55];
int dp[55][55][2][4];
int n, k;
int sol(int x, int y, int dir, int cnt) {
	if (x == n && y == n) return 1;
	int& ret = dp[x][y][dir][cnt];
	if (ret != -1) return ret;
	ret = 0;
	if (dir == 0) {
		if (x + 1 <= n && a[x + 1][y] == 0) ret += sol(x + 1, y, dir, cnt);
		if (y + 1 <= n && a[x][y + 1] == 0 && cnt < k) ret += sol(x, y + 1, dir ^ 1, cnt + 1);
	}
	else {
		if (x + 1 <= n && a[x + 1][y] == 0 && cnt < k) ret += sol(x + 1, y, dir ^ 1, cnt + 1);
		if (y + 1 <= n && a[x][y + 1] == 0) ret += sol(x, y + 1, dir, cnt);
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			for (int j = 1; j <= n; j++) {
				if (s[j - 1] == '.') a[i][j] = 0;
				else a[i][j] = 1;
			}
		}
		ini(dp, -1);
		int ans = 0;
		if (a[1][2] == 0) ans += sol(1, 2, 1, 0);
		if (a[2][1] == 0) ans += sol(2, 1, 0, 0);
		cout << ans<<'\n';
	}
}