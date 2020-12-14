/* [BOJ 15458] Barn Painting
	Algorithm : Tree DP

	���� ��尡 ��ĥ�� �̹� �Ǿ��ִٸ�, �� ���� ������ ������ ĥ���� �ڽĳ�常 �����ϴ�. 
	���� ��ĥ�Ǿ����� �ʴٸ�, �����忡 ĥ���� �� ���򸶴� ���� ������ش�. 
	(dp[i][1] ~ dp[i][3])
	top-down ������� tree dp�� �����Ѵ�.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int A[100001];
vector<int>adj[100001];
ll dp[100001][4];
void sol(int u, int p) {
	if (A[u] >= 1) dp[u][A[u]] = 1;
	else {
		dp[u][1] = dp[u][2] = dp[u][3] = 1;
	}
	for (int v : adj[u]) {
		if (v == p) continue;
		sol(v, u);
		if (A[u] == 1) {
			dp[u][1] *= dp[v][2] + dp[v][3];
			dp[u][1] %= MOD;
		}
		else if (A[u] == 2) {
			dp[u][2] *= dp[v][1] + dp[v][3];
			dp[u][2] %= MOD;
		}
		else if (A[u] == 3) {
			dp[u][3] *= dp[v][1] + dp[v][2];
			dp[u][3] %= MOD;
		}
		else {
			dp[u][1] *= dp[v][2] + dp[v][3];
			dp[u][2] *= dp[v][1] + dp[v][3];
			dp[u][3] *= dp[v][2] + dp[v][1];
			dp[u][1] %= MOD;
			dp[u][2] %= MOD;
			dp[u][3] %= MOD;
		}
	}
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, K; cin >> N >> K;
	for (int i = 1; i < N; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= K; i++) {
		int b, c; cin >> b >> c;
		A[b] = c;
	}
	sol(1, 1);
	ll ans = 0;
	for (int i = 1; i <= 3; i++) {
		ans += dp[1][i];
	}
	cout << ans % MOD;
}