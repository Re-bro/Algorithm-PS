/* [BOJ 12995] 트리나라
	Algorithm : Tree DP

	dp[u][k] = u를 루트로 하는 서브트리중 k개의 노드를 가지는 서브트리의 수라고 하고, 
	노드 u의 자식을 순서대로 자식으로 포함시키면서 계산한다.
	현재 자식을 v라고 할 때, dp[u][k]는 u를 루트로 하는 서브트리에 지금까지 포함되어있는 자식들 중 i개를 뽑고, 
	v를 루트로 하는 서브트리에서 k-i개를 뽑으면 되므로 dp[u][k] += dp[u][i]* dp[v][k-i]를 만족한다. 
	
	dp[u][0] = dp[u][1] = 1로 전처리를 해주는 것에 유의
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);

vector<int> adj[51];
ll dp[51][51];
int N, K;
void sol(int u, int p) {
	for (int v : adj[u]) {
		if (v == p) continue;
		sol(v, u);
		for (int i = K; i >=2; i--) { //중복 피하기 위해 K부터
			for (int j = 1; j < i; j++){
				dp[u][i] += dp[u][j] * dp[v][i - j];
				dp[u][i] %= MOD;
			}
		}
	}
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 1; i < N; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) dp[i][0] = dp[i][1] = 1;
	sol(1, 1);
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += dp[i][K];
		ans %= MOD;
	}
	cout << ans;
}