/* [BOJ 1033] Ĭ����
	Algorithm : Euclidean Algorithm / Graph search

	�־����� N-1���� ��� �ֿ��� �� ���� �������� �����ϸ� ������ N���� Ʈ���� ���������.
	����, Ʈ���� ������ �ϳ��� �߰��ذ��� ������� �����ؼ�, 
	�� ������ ������ŭ ���� �� ������ �����ϰ� �����ְ�, �̹� ������� Ʈ���� Ÿ�� ���鼭
	�ش� ������ ������ ��ŭ �ٸ� �������� �����ش�. 

	���������� �� ������ �ִ������� ���ؼ� ��� �������ش�.
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