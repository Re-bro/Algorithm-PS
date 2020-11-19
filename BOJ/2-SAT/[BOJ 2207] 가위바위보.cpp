/* [BOJ 2207] 가위바위보
	Algorithm : 2-SAT

	전형적인 2-SAT 알고리즘 유형
	별다른 아이디어나 스킬이 필요 없다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);
vector<vector<int>>adj;
int dfs_n[20001], sn[20001], SN, cnt;
stack<int>S;

int dfs(int u) {
	dfs_n[u] = ++cnt;
	int ret = dfs_n[u];
	S.push(u);
	for (int v : adj[u]) {
		if (dfs_n[v] == 0) ret = min(ret, dfs(v));
		else if (sn[v] == -1) ret = min(ret, dfs_n[v]);
	}
	if (dfs_n[u] == ret) {
		while (1) {
			int k = S.top(); S.pop();
			sn[k] = SN;
			if (k == u) break;
		}
		SN++;
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M; cin >> N >> M;
	ini(sn, -1);
	adj.assign(2 * N + 1, vector<int>());
	for (int i = 1; i <= N; i++) {
		int a, b; cin >> a >> b;
		a = (a < 0) ? -a * 2 : a * 2 - 1;
		b = (b < 0) ? -b * 2 : b * 2 - 1;
		if (a % 2) adj[a + 1].push_back(b);
		else adj[a - 1].push_back(b);
		if (b % 2) adj[b + 1].push_back(a);
		else adj[b - 1].push_back(a);
	}
	for (int i = 1; i <= 2 * N; i++) {
		if (dfs_n[i] == 0) dfs(i);
	}
	for (int i = 1; i <= 2*N; i+=2) {
		if (sn[i] == sn[i + 1]) {
			cout << "OTL";
			return 0;
		}
	}
	cout << "^_^";
}
