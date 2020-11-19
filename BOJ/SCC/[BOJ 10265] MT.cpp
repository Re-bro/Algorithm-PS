/* [BOJ 10265] MT
	Algorithm : SCC / DP / 0-1 knapsack

	A가 안가면 B가 안갈 때, A->B로 그래프 연결
	cycle인 경우에는 cycle에 속하는 사람들이 모두 타거나, 모두 타지 않아야 함
	scc 그래프 생성-> DAG에서 반드시 부모가 버스에 타야 자식도 버스에 탈 수 있음
	scc 그래프의 각 컴포넌트별로 최대 인원(mx), 최소 인원(mi) 저장 (최대 인원 = 컴포넌트 총 인원, 최소 인원 = root노드의 인원)
	[mi, mx] 범위만큼 knapsack dp
	(각 컴포넌트별로 최대 1개의 사이클만 존재할 수 있으므로 [mi, mx]범위의 모든 자연수 값이 다 가능)
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
int sn[1001], dfs_n[1001], SN, cnt, cn[1001];
int mx[1001], dp[1001], in[1001];
stack<int> S;
vector<vector<int>>sccadj;
vector<int> tmp;
int dfs(int u) {
	dfs_n[u] = ++cnt;
	S.push(u);
	int ret = dfs_n[u];
	for (int v : adj[u]) {
		if (dfs_n[v] == 0) ret = min(ret, dfs(v));
		else if (sn[v] == -1) ret = min(ret, dfs_n[v]);
	}
	if (ret == dfs_n[u]) {
		while (1) {
			int k = S.top(); S.pop();
			sn[k] = SN;
			cn[SN]++;
			if (k == u) break;
		}
		SN++;
	}
	return ret;
}
int dfs2(int u) {
	int ret = cn[u];
	for (int v : sccadj[u]) {
		ret += dfs2(v);
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	adj.assign(n + 1, vector<int>());
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		adj[a].push_back(i);
	}
	ini(sn, -1);
	for (int i = 1; i <= n; i++) {
		if (dfs_n[i] == 0) dfs(i);
	}
	sccadj.assign(SN, vector<int>());
	for (int i = 1; i <= n; i++) {
		for (int v : adj[i]) {
			if (sn[i] != sn[v]) {
				sccadj[sn[i]].push_back(sn[v]);
				in[sn[v]]++;
			}
		}
	}
	ini(dp, -1);
	dp[0] = 0;
	for (int i = 0; i < SN; i++) {
		if (in[i] == 0) {
			int mx = dfs2(i);
			for (int j = k; j >= 0; j--) {
				for (int q = mx; q >= cn[i]; q--) {
					if (j - q >= 0 && dp[j - q] == 0) dp[j] = 0;
				}
			}
		}
	}
	for (int i = k; i >= 0; i--) {
		if (dp[i] == 0) {
			cout << i;
			return 0;
		}
	}
}
