/* [BOJ 16404] 주식회사 승범이네
	Algorithm : Segment Tree or Fenwick Tree / Euler-tour technique

	dfs 방문 순서대로 정점별로 번호를 매기고, 각 정점별로 자신의 자식들의 번호 범위를 구해놓는다.
	만약 현재 정점의 번호가 3이고, 자손들의 번호가 7까지 있다면 
	해당 정점은 3~7의 구간을 포함하게 되는 것이다. 
	따라서 이후에 세그먼트 트리 (Range update) 를 이용해준다.
*/

#include<bits/stdc++.h>
using namespace std;
int tr[100001];
int N, M;
int sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += tr[i];
		i -= (i&-i);
	}
	return ans;
}
void update(int i, int val) {
	while (i < N + 1) {
		tr[i] += val;
		i += (i&-i);
	}
}
vector<int>adj[100001];
int num = 0;
int L[100001], R[100001];
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
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		if (a != -1) {
			adj[a].push_back(i);
		}
	}
	dfs(1);
	for (int i = 1; i <= M; i++) {
		int a; cin >> a;
		if (a == 1) {
			int b, c; cin >> b >> c;
			update(L[b], c);
			update(R[b] + 1, -c);
		}
		else {
			int b; cin >> b;
			cout << sum(L[b]) << '\n';
		}
	}
}