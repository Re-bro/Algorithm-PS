/*
	[BOJ 17075] 유물 복원
	Algorithm : DP / Math
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

int cnt[51][51];
int a[51][51];
bool dp[2501][2501][2];
int n, m, k;
vector<pair<int, pii>> v;
bool done = false;
void sol(int idx, int now) {
	if (idx == -1) {
		return;
	}
	if (dp[idx][now][0]) {
		sol(idx - 1, now);
	}
	else {
		a[v[idx].se.fi][v[idx].se.se] = 1;
		sol(idx - 1, (k + now - v[idx].fi) % k);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			cnt[i][j] = i * (n + 1 - i) * j * (m + 1 - j);
			if (a[i][j] == 1) sum += cnt[i][j];
			else if (a[i][j] == -1) v.pb({ cnt[i][j] % k, {i, j} });
		}
	}
	sum %= k;
	bool chk = false;
	if (sum == 0) chk = true;
	else {
		for (int i = 0; i < sz(v); i++) {
			if (i == 0) {
				dp[0][0][0] = true;
				dp[0][v[0].fi][1] = true;
			}
			else {
				for (int j = 0; j < 2500; j++) {
					if (dp[i - 1][j][0] || dp[i - 1][j][1]) {
						dp[i][j][0] = true;
						dp[i][(j + v[i].fi) % k][1] = true;
					}
				}
			}
			if (dp[i][k - sum][1]) {
				sol(i, k - sum);
				chk = true;
				break;
			}
		}
	}
	if (!chk) cout << -1;
	else {
		cout << 1 << '\n';
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j] == -1) cout << 0 << ' ';
				else cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
	}

}