/* [BOJ 1949] ��� ����
	Algorithm : Tree DP

	�־��� �׷����� Ʈ���̹Ƿ�, �� ��庰�� �θ� ���� �ڽ� ��常 ������ָ�
	������ ������ ���ؼ� ��� ����� �����ϴ�. 
	dfs�� ��ȸ�ϸ鼭, ���� ������ ��� ������ �����ϱ� ���ؼ��� �ڼյ��� ��� ��� ������ �ƴϾ�� �Ѵ�. 
	�ݸ�, ���� ������ ��� ������ �������� �ʴ´ٸ�
	�ڼյ��� ��� ������ ���ο� ������� �ִ��� ���� ���� ��츦 ����ϸ� �ȴ�. 
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
int dp[10001][2];
bool visited[10001];
void sol(int u, int p) {
	for (int v : adj[u]) {
		if (v == p) continue;
		sol(v, u);
		dp[u][0] += max(dp[v][0], dp[v][1]);
		dp[u][1] += dp[v][0];
	}
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> dp[i][1];
	for (int i = 1; i < N; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	sol(1, 1);
	cout << max(dp[1][0], dp[1][1]);
}