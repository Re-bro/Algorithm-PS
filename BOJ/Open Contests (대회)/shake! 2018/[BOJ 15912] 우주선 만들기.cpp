/* [BOJ 15912] 우주선 만들기
	Algorithm : DP

	X < Y인 부품에서 Y를 X보다 먼저 구매할 수는 없으므로 앞에서부터 차례대로
	구매하는 부품 묶음을 고려하면 된다. 
	dp[i] = dp[i-j] + max(e_x)*max(w_x) (x = j+1 ~ i)
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);

ll w[1001], e[1001];
ll dp[1001];
int N;
ll sol(int idx) {
	if (idx == N + 1) return 0;
	ll &ret = dp[idx];
	if (ret != -1) return ret;
	ret = (ll)1e18;
	ll em = 0, wm = 0;
	for (int i = idx; i <= N; i++) {
		em = max(em, e[i]);
		wm = max(wm, w[i]);
		ret = min(ret, em*wm + sol(i + 1));
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> w[i];
	for (int i = 1; i <= N; i++) cin >> e[i];
	ini(dp, -1);
	cout << sol(1);
}