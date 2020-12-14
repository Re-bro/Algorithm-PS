/* [BOJ 17831] ���� �¹��̳�
	Algorithm : Tree DP

	dp[i][k] = i�� ��尡 ��Ʈ�� ����Ʈ������ ���� �� �ִ� �ִ��� ��
	k = i�� ��尡 ���丵 ���迡 ���ԵǸ� 1, �ƴϸ� 0
	dp[i][0]�� i�� ��尡 ���丵 ���迡 ������ �ȵǹǷ� 
	�׻� �ڽĳ�� j ���� ��Ʈ�� �ϴ� ����Ʈ������ �ִ��� �������� �ȴ�. max(dp[j][0], dp[j][1])
	�ݸ�, dp[i][1]�� i�� ���� ���丵 ���迡 ���Ե� �ڽ� �ϳ��� �ʿ��ϰ�, ����
	dp[i][1] = max(dp[i][1], A[i]*A[j] + dp[j][0] + ������ �ڽ� ������ max(dp[j][0], dp[j][1])) �� �ȴ�.
*/

#include<bits/stdc++.h>

using namespace std;
using ll = long long;
vector<int> adj[200001];
ll A[200001];
ll dp[200001][2];
ll both[200001];
void sol(int u) {
	ll val = 0;
	for (int v : adj[u]) {
		sol(v);
		dp[u][0] += both[v];
		val += both[v];
	}
	for (int v : adj[u]) {
		dp[u][1] = max(dp[u][1], A[u] * A[v] + dp[v][0] - both[v] + val);
	}
	both[u] = max(dp[u][0], dp[u][1]);
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	for (int i = 2; i <= N; i++) {
		int a; cin >> a;
		adj[a].push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	sol(1);
	cout << max(dp[1][0], dp[1][1]);
}