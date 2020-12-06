/* [BOJ 18876] Exercise
	Algorithm : Prime number / DP

	Ç®ÀÌ : http://www.usaco.org/current/data/sol_exercise_gold_open20.html
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
int N;
ll M;
ll p[10001];
vector<int> P;
ll dp[10001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 2; i <= N; i++) {
		if (p[i] == 0) {
			P.push_back(i);
			for (int j = 2; j*i <= N; j++) {
				p[i * j] = 1;
			}
		}
	}
	dp[0] = 1;
	for (int i = 0; i < sz(P); i++) {
		for (int j = N; j >= 0; j--) {
			for (int k = P[i]; k <= j; k *= P[i]) {
				dp[j] = (dp[j] + dp[j - k] * k) % M;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i <= N; i++) {
		ans += dp[i];
		ans %= M;
	}
	cout << ans;
}