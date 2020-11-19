/* [BOJ 1506] 경찰서
	Algorithm : SCC

	한 SCC 내에서는 하나의 경찰서로 모든 도시를 통제할 수 있다.
	따라서 각 SCC별로 최소 비용을 갖는 경찰서를 세운다. 
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
int w[101], dfs_n[101], SN, cnt, sn[101];
stack<int> S;
int ans = 0;
vector<vector<int>>adj(101, vector<int>());
int dfs(int u) {
	dfs_n[u] = ++cnt;
	int ret = dfs_n[u];
	S.push(u);
	for (int v : adj[u]) {
		if (dfs_n[v] == 0) ret = min(ret, dfs(v));
		else if (sn[v] == -1) ret = min(ret, dfs_n[v]);
	}
	if (ret == dfs_n[u]) {
		int mi = MAX;
		while (1) {
			int k = S.top(); S.pop();
			mi = min(w[k], mi);
			sn[k] = SN;
			if (k == u) break;
		}
		ans += mi;
		SN++;
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> w[i];
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		for (int j = 0; j < sz(s); j++) {
			if (s[j] == '1') adj[i].push_back(j + 1);
		}
	}
	ini(sn, -1);
	for (int i = 1; i <= N; i++) if (dfs_n[i] == 0) dfs(i);
	cout << ans;
}
