/* [BOj 1814] ���� ��ĥ�ϱ�
	Algorithm : Tree DP
	
	dp[u][i] = u�� i��° ���� ĥ���� �� u�� ��Ʈ�� �ϴ� subtree�� �ּ� ���
	�ּҺ���� ���ϴ� ���������� logN���� ���� ������ ���
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

vector<int>adj[10001];
int C[10001];
int dp[10001][15];
int N, M;
void sol(int u, int p) {
	for (int v : adj[u]) {
		if (v == p) continue;
		sol(v, u);
		for (int i = 1; i <= min(14, M); i++) {
			int tmp = MAX;
			for (int j = 1; j <= min(14, M); j++) {
				if (i != j) tmp = min(tmp, dp[v][j]);
			}
			dp[u][i] += tmp;
		}
	}
	for (int i = 1; i <= min(14, M); i++) {
		dp[u][i] += C[i];
	}
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> C[i];
	}
	sort(C + 1, C + 1 + M);
	sol(1, 1);
	int ans = MAX;
	for (int i = 1; i <= min(14, M); i++) {
		ans = min(ans, dp[1][i]);
	}
	cout << ans;
}