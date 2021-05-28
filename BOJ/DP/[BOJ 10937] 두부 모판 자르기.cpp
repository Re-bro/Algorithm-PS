/*
	[BOJ 10937] 두부 모판 자르기
	Algorithm : DP / Bit DP
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
int n;
vector<string> v;
int dp[11][11][1 << 12];
int cal(char a, char b) {
	if (a > b) swap(a, b);
	if (b == 'F') return 0;
	if (a == 'A') {
		if (b == 'A') return 100;
		else if (b == 'B') return 70;
		else if (b == 'C') return 40;
	}
	else if (a == 'B') {
		if (b == 'B') return 50;
		else if (b == 'C') return 30;
	}
	else if (a == 'C') {
		return 20;
	}
}
int sol(int x, int y, int bit) {
	if (x == n) {
		if (bit == 0) return 0;
		else return -MAX;
	}
	int &ret = dp[x][y][bit];
	if (ret != -1) return ret;
	ret = -MAX;
	if (bit & 1) {
		if (y == n - 1) return ret = sol(x + 1, 0, bit >> 1);
		else return ret = sol(x, y + 1, bit >> 1);
	}
	else {
		if ((bit & 3) == 0) {
			if (y < n - 2) {
				ret = max(ret, sol(x, y + 2, bit >> 2) + cal(v[x][y], v[x][y + 1]));
			}
			else if (y == n - 2) {
				ret = max(ret, sol(x + 1, 0, bit >> 2) + cal(v[x][y], v[x][y + 1]));
			}
		}
		if (x < n - 1) {
			if (y < n - 1) ret = max(ret, sol(x, y + 1, (bit >> 1) | (1 << (n - 1))) + cal(v[x][y], v[x + 1][y]));
			else ret = max(ret, sol(x + 1, 0, (bit >> 1) | (1 << (n - 1))) + cal(v[x][y], v[x + 1][y]));
		}
		if (y < n - 1) ret = max(ret, sol(x, y + 1, bit >> 1));
		else ret = max(ret, sol(x + 1, 0, bit >> 1));
		return ret;
	}
	
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n;
	v.assign(n, string());
	ini(dp, -1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << sol(0, 0, 0);
}