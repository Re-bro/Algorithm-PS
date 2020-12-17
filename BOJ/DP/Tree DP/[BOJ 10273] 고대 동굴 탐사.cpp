/* [BOJ 10273] ��� ���� Ž��
	Algorithm : Tree DP

	dp[i] = i���� ����ؼ� ���� �� �ִ� �ִ��� ����
	u���� ���� ����� v�� �� ������, dp[v]���� Ce��ŭ �� ������ ���� �� �ִ�.
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using pii = pair<int, int>;

int v[20001], dp[20001], P[20001];
vector<vector<pii>> adj;
int sol(int u) {
	int &ret = dp[u];
	if (ret != -1) return ret;
	ret = v[u];
	for (pii a : adj[u]) {
		int k = v[u] + sol(a.first) - a.second;
		if (ret < k) {
			P[u] = a.first;
			ret = k;
		}
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, E; cin >> N >> E;
		ini(dp, -1);
		ini(P, -1);
		for (int i = 1; i <= N; i++) cin >> v[i];
		adj.assign(N + 1, vector<pii>());
		for (int i = 1; i <= E; i++) {
			int a, b, c; cin >> a >> b >> c;
			adj[a].push_back({ b, c });
		}
		int val = sol(1);
		vector<int> ans;
		for (int i = 1; i != -1; i = P[i]) {
			ans.push_back(i);
		}
		cout << val << ' ' << sz(ans) << '\n';
		for (int i : ans) cout << i << ' ';
		cout << '\n';
	}
}