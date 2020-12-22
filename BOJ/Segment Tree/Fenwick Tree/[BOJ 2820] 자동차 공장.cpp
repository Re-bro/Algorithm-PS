/* [BOJ 2820] 자동차 공장
	Algorithm : Segment Tree or Fenwick Tree / Euler-tour technique

	Range update & point Query
	16404번과 비슷한 문제
*/

#include<bits/stdc++.h>
using namespace std;

int N, M;
int A[500001], L[500001], R[500001], tr[500010];
vector<int>adj[500001];
int num = 0;
int sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += tr[i];
		i -= (i & -i);
	}
	return ans;
}
void update(int i, int val) {
	while (i <= N+1) {
		tr[i] += val;
		i += (i & -i);
	}
}
void dfs(int u) {
	L[u] = ++num;
	for (int v : adj[u]) {
		dfs(v);
	}
	R[u] = num;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> M;
	cin >> A[1];
	for (int i = 2; i <= N; i++) {
		cin >> A[i];
		int a;  cin >> a;
		adj[a].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= N; i++) {
		update(L[i], A[i]); update(L[i] + 1, -A[i]);
	}
	for (int i = 1; i <= M; i++) {
		char c; cin >> c;
		if (c == 'p') {
			int a, x; cin >> a >> x;
			if (L[a] < R[a]) {
				update(L[a] + 1, x);
				update(R[a] + 1, -x);
			}
		}
		else {
			int a; cin >> a;
			cout << sum(L[a]) << '\n';
		}
	}
}