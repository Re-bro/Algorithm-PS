/*
	[Tarjan's Algorithm] SCC & 2-SAT
	O(|V| + |E|)
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define MAX 10000

using namespace std;

stack<int> S;
vector<vector<int>> SCC;
int dfs_n[MAX], sn[MAX]; // scc number 
vector<vector<int>> adj;
int SN, cnt, n;

int dfs(int u) {
	dfs_n[u] = ++cnt;
	int ret = dfs_n[u];
	S.push(u);
	for (int v : adj[u]) {
		if (dfs_n[v] == 0) ret = min(ret, dfs(v));
		else if (sn[v] == -1) ret = min(ret, dfs_n[v]); // v is not in scc
	}
	if (ret == dfs_n[u]) {
		vector<int> tmp;
		while (1) {
			int t = S.top(); S.pop();
			tmp.push_back(t);
			sn[t] = SN;
			if (t == u) break;
		}
		sort(all(tmp));
		SCC.push_back(tmp); // collect SCC
		SN++;
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	memset(sn, -1, sizeof(sn));
	for (int i = 1; i <= 2 * n; i++) if (dfs_n[i] == 0) dfs(i);
	
	// 2 - SAT
	for (int i = 1; i <= 2 * n; i += 2) {
		if (sn[i] == sn[i + 1]) return cout << "No Answer", 0;
	}
	for (int i = 1; i <= 2 * n; i += 2) cout << (sn[i] < sn[i + 1]) << ' ';

	// create new graph of scc
	vector<vector<int>>sccadj(SN, vector<int>());
	for (int i = 1; i <= MAX; i++) {
		for (int j : adj[i]) {
			if (sn[i] != sn[j]) sccadj[sn[i]].push_back(sn[j]);
		}
	}

}
