/*
	[BOJ 20970] Dance Mooves
	Algorithm : DFS / Permutation
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> chk[100001];
int go[100001], ans[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) v[i] = i, chk[i].push_back(i);
	for (int i = 1; i <= k; i++) {
		int a, b; cin >> a >> b;
		chk[v[a]].push_back(b);
		chk[v[b]].push_back(a);
		swap(v[a], v[b]);
	}
	for (int i = 1; i <= n; i++) {
		go[v[i]] = i;
	}
	vector<bool> visited(n + 1);
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		int now = i;
		set<int> s;
		for (int j : chk[now]) s.insert(j);
		vector<int> trace;
		trace.push_back(now);
		while (go[now] != i) {
			now = go[now];
			visited[now] = true;
			trace.push_back(now);
			for (int j : chk[now]) s.insert(j);
		}
		for (int j : trace) {
			ans[j] = s.size();
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}