/* [BOJ 14586] 도미노 (Small)
	Algorithm : DP

	dp[i][j] = [i, j] 구간의 도미노를 넘어뜨리는 최소 횟수
	각 도미노별로 해당 도미노를 넘어뜨렸을 때, 좌우로 넘어지는 최대 도미노를 L, R에 저장해둔다.
	왼쪽으로 넘어뜨리는 경우와 오른쪽으로 넘어뜨리는 경우 모두 고려해준다.
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const int MAX = (int)2e9;

int dp[301][301];
int L[301], R[301];
vector<pll> v;
int sol(int l, int r) {
	if (l > r) return 0;
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	ret = MAX;
	for (int i = l; i <= r; i++) {
		ret = min(ret, sol(R[i] + 1, r) + sol(l, i - 1) + 1);
		ret = min(ret, sol(l, L[i] - 1) + sol(i + 1, r) + 1);
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	ini(dp, -1);
	for (int i = 0; i < n; i++) {
		int x, h; cin >> x >> h;
		v.push_back({ x, h });
	}
	sort(all(v));
	for (int i = 0; i < sz(v); i++) {
		int mi = 1;
		int mx = n;
		ll last = v[i].first - v[i].second;
		for (int j = i-1; j >= 0; j--) {
			if (last <= v[j].first) {
				last = min(last, v[j].first - v[j].second);
			}
			else {
				mi = j + 2;
				break;
			}
		}
		last = v[i].first + v[i].second;
		for (int j = i + 1; j < n; j++) {
			if (last >= v[j].first) {
				last = max(last, v[j].first + v[j].second);
			}
			else {
				mx = j;
				break;
			}
		}
		L[i + 1] = mi;
		R[i + 1] = mx;
	}
	cout << sol(1, n);
}