/* [BOJ 2337] Ʈ�� �ڸ���
	Algorithm : Tree DP

	dp[u][k] = u�� ��Ʈ�� �ϴ� ����Ʈ������ k�� ��尡 ������ �ڸ��� �ּ� Ƚ����� �ϸ�
	dp[u][i+j] = min(dp[u][i+j], dp[u][i] + dp[v][j]) �̴�. (v�� �ڼ�)
	�� ��, �⺻������ dp[u][1]�� ó���� 0�̹Ƿ� ��ó�� ���ְ�, 
	j�� 0�� ���� �ڼ��� ������ �ʴ� ���, �� �ڸ��� ����̱� ������ + dp[v][j] ��� +1 �� ���ش�.

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[151];
int sub[151], tmp[151], dp[151][151];
int n, m;
void sol(int u, int p) {
	sub[u] = 1;
	for (int v : adj[u]) {
		if (v == p) continue;
		sol(v, u);
		sub[u] += sub[v];
		fill(tmp, tmp + n + 1, 10000);
		for (int i = 1; i <= sub[u]; i++) {
			for (int j = 0; j <= sub[v]; j++) {
				tmp[i+j] = min(tmp[i+j], dp[u][i] + (j == 0 ? 1 : dp[v][j]));
			}
		}
		for (int i = 1; i <= n; i++) dp[u][i] = tmp[i];
	}
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		dp[i][1] = 0;
		for (int j = 2; j <= n; j++) dp[i][j] = 10000;
	}
	sol(1, 1);
	int ans = 10000;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, dp[i][m] + (i == 1 ? 0 : 1));
	}
	cout << ans;
}