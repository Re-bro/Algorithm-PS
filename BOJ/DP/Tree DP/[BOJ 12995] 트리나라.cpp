/* [BOJ 12995] Ʈ������
	Algorithm : Tree DP

	dp[u][k] = u�� ��Ʈ�� �ϴ� ����Ʈ���� k���� ��带 ������ ����Ʈ���� ����� �ϰ�, 
	��� u�� �ڽ��� ������� �ڽ����� ���Խ�Ű�鼭 ����Ѵ�.
	���� �ڽ��� v��� �� ��, dp[u][k]�� u�� ��Ʈ�� �ϴ� ����Ʈ���� ���ݱ��� ���ԵǾ��ִ� �ڽĵ� �� i���� �̰�, 
	v�� ��Ʈ�� �ϴ� ����Ʈ������ k-i���� ������ �ǹǷ� dp[u][k] += dp[u][i]* dp[v][k-i]�� �����Ѵ�. 
	
	dp[u][0] = dp[u][1] = 1�� ��ó���� ���ִ� �Ϳ� ����
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
		for (int i = K; i >=2; i--) { //�ߺ� ���ϱ� ���� K����
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