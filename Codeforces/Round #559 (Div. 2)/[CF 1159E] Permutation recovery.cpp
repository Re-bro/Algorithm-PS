/*
	[CF 1159E] Permutation recovery
	Algorithm : dfs / math
*/
#include<bits/stdc++.h>
using namespace std;

int nex[500010];
vector<int> adj[500010];
int cnt;
int p[500010];
void dfs(int u) {
	p[u] = cnt--;
	for (int v : adj[u]) dfs(v);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 1; i <= n + 1; i++) adj[i].clear();
		for (int i = 1; i <= n; i++) {
			cin >> nex[i];
			if (nex[i] == -1) nex[i] = i + 1;
			adj[nex[i]].push_back(i);
		}
		cnt = n+1;
		dfs(n + 1);
		stack<int> s;
		bool chk = true;
		for (int i = n; i >= 1; i--) {
			while (!s.empty() && p[s.top()] < p[i]) s.pop();
			//i < j < next_i < next_j  => No answer
			if ((s.empty() && nex[i] != n + 1) || (!s.empty() && s.top() != nex[i])) chk = false;
			s.push(i);
		}
		if (!chk) cout << -1 << '\n';
		else {
			for (int i = 1; i <= n; i++) cout << p[i] << ' ';
			cout << '\n';
		}
	}
}