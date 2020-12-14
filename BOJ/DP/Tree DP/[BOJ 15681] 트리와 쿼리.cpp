/* [BOJ 15681] 트리와 쿼리
	Algorithm : Tree DP
 
	트리 dp의 기본적인 유형이다. 
	자식노드를 루트로 하는 모든 서브트리에 속한 정점의 개수 + 1이 
	자신이 루트로 하는 서브트리에 속한 정점의 개수이다.
*/
#include<bits/stdc++.h>
using namespace std;

int sub[100001];
vector<int>adj[100001];
int sol(int u, int p) {
	for (int v : adj[u]) {
		if (v == p) continue;
		sub[u] += sol(v, u);
	}
	return ++sub[u];
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, R, Q; cin >> N >> R >> Q;
	for (int i = 1; i < N; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	sol(R, R);
	for (int i = 1; i <= Q; i++) {
		int a; cin >> a;
		cout << sub[a] << '\n';
	}
}