/* [BOJ 14287] 내리 칭찬 3
	Algorithm : Fenwick Tree

	현재 직원이 칭찬을 받으면 현재 정점을 자손으로 하는 모든 상사가 칭찬을 받으므로
	현재 직원에 대해서 점 업데이트를 해준다.
	그리고 칭찬을 받은 정도를 구하기 위해서는 현재 직원을 루트로 하는 서브트르 범위
	즉, L[i] ~ R[i] 구간의 합을 구하면 된다.

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
	bool down = true;
	for (int i = 1; i <= m; i++) {
		int a; cin >> a;
		if (a == 1) {
			int b, c; cin >> b >> c;
				update(L[b], c);
		}
		else {
			int b; cin >> b;
			cout<<sum(R[b]) - sum(L[b]-1)<<'\n';
		}
	}
}