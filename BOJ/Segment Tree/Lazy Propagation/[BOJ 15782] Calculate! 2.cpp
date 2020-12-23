/* [BOJ 15782] Calculate! 2
	Algorithm : Lazy propagation / Segment Tree / Euler-tour technique

	주어지는 쿼리들은 정점 x를 기준으로 하며, x를 루트로 하는 서브트리의 모든 노드에 영향을 준다.
	따라서 오일러 투어 테크닉으로 dfs 방문 순서를 구하고,
	자신을 루트로 하는 서브트리의 노드 번호의 범위를 각 정점마다 구한다.

	xor의 경우, 현재 노드의 범위가 짝수개인 경우 같은 값을 짝수번 xor하면 0이되므로
	홀수개인 경우에만 xor을 해주면 된다.

*/
#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int N, M;
vector<int>adj[100001];
int num = 0;
int L[100001], R[100001], tr[400001], lazy[400001], A[100001], dfs_n[100001];
void dfs(int u, int p) {
	L[u] = ++num;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
	R[u] = num;
}
void update_lazy(int x, int s, int e);
int init(int x, int s, int e) {
	if (s == e) return tr[x] = A[dfs_n[s]];
	else return tr[x] = init(x * 2, s, (s + e) / 2) ^ init(x * 2 + 1, (s + e) / 2 + 1, e);
}
int query(int x, int s, int e, int l, int r) {
	update_lazy(x, s, e);
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tr[x];
	else return query(x * 2, s, (s + e) / 2, l, r) ^ query(x * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
void update_query(int x, int s, int e, int l, int r, int val) {
	update_lazy(x, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r) {
		if ((e - s + 1) % 2) tr[x] ^= val;
		if (s != e) {
			lazy[x * 2] ^= val;
			lazy[x * 2 + 1] ^= val;
		}
		return;
	}
	update_query(x * 2, s, (s + e) / 2, l, r, val);
	update_query(x * 2 + 1, (s + e) / 2 + 1, e, l, r, val);
	tr[x] = tr[x * 2] ^ tr[x * 2 + 1];
}
void update_lazy(int x, int s, int e) {
	if (lazy[x] != 0) {
		if((e - s + 1) % 2) tr[x] ^= lazy[x];
		if (s != e) {
			lazy[x * 2] ^= lazy[x];
			lazy[x * 2 + 1] ^= lazy[x];
		}
		lazy[x] = 0;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> M;
	for (int i = 1; i < N; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		dfs_n[L[i]] = i;
	}
	init(1, 1, N);
	for (int i = 1; i <= M; i++) {
		int a; cin >> a;
		if (a == 1) {
			int x; cin >> x;
			cout << query(1, 1, N, L[x], R[x])<<'\n';
		}
		else {
			int x, y; cin >> x >> y;
			update_query(1, 1, N, L[x], R[x], y);
		}
	}
}