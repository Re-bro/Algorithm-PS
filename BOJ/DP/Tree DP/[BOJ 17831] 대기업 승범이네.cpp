/* [BOJ 17831] 대기업 승범이네
	Algorithm : Tree DP

	dp[i][k] = i번 노드가 루트인 서브트리에서 가질 수 있는 최대의 값
	k = i번 노드가 멘토링 관계에 포함되면 1, 아니면 0
	dp[i][0]은 i번 노드가 멘토링 관계에 포함이 안되므로 
	항상 자식노드 j 들이 루트로 하는 서브트리에서 최댓값을 가져오면 된다. max(dp[j][0], dp[j][1])
	반면, dp[i][1]은 i번 노드와 멘토링 관계에 포함될 자식 하나가 필요하고, 따라서
	dp[i][1] = max(dp[i][1], A[i]*A[j] + dp[j][0] + 나머지 자식 노드들의 max(dp[j][0], dp[j][1])) 가 된다.
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