/* [BOJ 1693] Ʈ�� ��ĥ�ϱ�
	Algorithm : Tree DP

	S(N) = �ݵ�� N���� ���� ��� �ּ� cost�� ��ĥ�� �� �ִ� �׷����� ��� �� �� �ּҶ� �ϸ�
	S(N) >= 2^(N-1)�̴�. 
	����, log(����� ����) ��ŭ�� ���� ������ �ǹǷ� dp[N][logN] ��ŭ �����Ͽ�
	Tree dp�� �̿����ָ� �ȴ�.
	https://blog.encrypted.gg/144
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;
vector<int> adj[100001];
int n;
int dp[100001][18];
void sol(int u, int p) {
	for (int v : adj[u]) {
		if (v == p) continue;
		sol(v, u);
		for (int i = 1; i < 18; i++) {
			int mi = MAX;
			for (int j = 1; j < 18; j++) {
				if(j != i) mi = min(mi, dp[v][j]);
			}
			dp[u][i] += mi;
		}
	}
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 18; j++) dp[i][j] = j;
	}
	sol(1, 1);
	int ans = MAX;
	for (int i = 1; i < 18; i++) ans = min(ans, dp[1][i]);
	cout << ans;
}