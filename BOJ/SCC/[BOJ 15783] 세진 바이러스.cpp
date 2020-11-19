/* [BOJ 15783] 세진 바이러스
	Algorithm : SCC

	사이클 내의 한 곳만 감염시켜도 사이클 전체가 감염된다.
	따라서 SCC로 묶어준다.
	DAG에서 indegree가 0인 곳만 감염시켜주면 전체가 감염된다.  
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

int dfs_n[100001], sn[100001], SN, cnt;
vector<vector<int>>adj;
stack<int>S;
int dfs(int u) {
	dfs_n[u] = ++cnt;
	int ret = dfs_n[u];
	S.push(u);
	for (int v : adj[u]) {
		if (dfs_n[v] == 0) ret = min(ret, dfs(v));
		else if (sn[v] == -1) ret = min(ret, dfs_n[v]);
	}
	if (ret == dfs_n[u]) {
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
	//	freopen("input.txt", "r", stdin);
	int N, M; cin >> N >> M;
	adj.assign(N + 1, vector<int>());
	for (int i = 1; i <= M; i++) {
		int a, b; cin >> a >> b;
		a++; b++;
		adj[a].push_back(b);
	}
	ini(sn, -1);
	for (int i = 1; i <= N; i++) if (dfs_n[i] == 0) dfs(i);
	vector<int> in(SN);
	for (int i = 1; i <= N; i++) {
		for (int v : adj[i]) {
			if (sn[i] != sn[v]) in[sn[v]]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < SN; i++) if (in[i] == 0) ans++;
	cout << ans;
}
