/* [BOJ 1033] 칵테일
	Algorithm : Euclidean Algorithm / Graph search

	주어지는 N-1개의 재료 쌍에서 각 쌍을 간선으로 생각하면 정점이 N개인 트리가 만들어진다.
	따라서, 트리에 정점을 하나씩 추가해가는 방식으로 생각해서, 
	두 정점의 비율만큼 각각 두 정점에 적절하게 곱해주고, 이미 만들어진 트리를 타고 가면서
	해당 정점에 곱해진 만큼 다른 정점에도 곱해준다. 

	마지막으로 각 정점의 최대공약수를 구해서 모두 나누어준다.
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
ll val[10];
vector<int>adj[10];
bool visited[10];
void dfs(int u, int p, ll a) {
	visited[u] = true;
	val[u] *= a;
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u, a);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	for (int i = 0; i < N; i++) val[i] = 1;
	for (int i = 1; i < N; i++) {
		int a, b; ll p, q; cin >> a >> b >> p >> q;
		ll k1 = val[b] * p; 
		ll k2 = val[a] * q;
		ll g = gcd(k1, k2);
		k1 /= g;
		k2 /= g;
		ini(visited, false);
		dfs(a, a, k1);
		if (!visited[b]) dfs(b, b, k2);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ll g = gcd(val[0], val[1]);
	for (int i = 1; i < N-1; i++) {
		g = gcd(g, val[i + 1]);
	}
	for (int i = 0; i < N; i++) {
		val[i] /= g;
		cout << val[i] << ' ';
	}
}