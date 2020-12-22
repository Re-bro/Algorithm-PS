/* [BOJ 14268] 내리 칭찬 2
	Algorithm : Fenwick Tree / Euler-tour technique

	16404번과 동일
*/
#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<int>adj[100001];
int L[100001], R[100001], tr[100001];
int num = 0;
void dfs(int u) {
	L[u] = ++num;
	for (int v : adj[u]) {
		dfs(v);
	}
	R[u] = num;
}
void update(int i, int val) {
	while (i <= n) {
		tr[i] += val;
		i += (i & -i);
	}
}
int sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += tr[i];
		i -= (i & -i);
	}
	return ans;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (a != -1) adj[a].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= m; i++) {
		int a; cin >> a;
		if (a == 1) {
			int b, c; cin >> b >> c;
			update(L[b], c);
			update(R[b] + 1, -c);
		}
		else {
			int b; cin >> b;
			cout<<sum(L[b])<<'\n';
		}
	}
}