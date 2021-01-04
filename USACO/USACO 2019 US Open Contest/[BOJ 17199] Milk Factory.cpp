/* [BOJ 17199] Milk Factory
	Algorithm : DFS / Brute-force

	�ܹ��� �������� �̷���� Ʈ���� �־��� ��, 
	�ٸ� ��� �������κ��� ���� ������ ������ �� �ִ� ���� �� ���� ��ȣ�� ���� ������ ���Ѵ�.
	N�� 100�̹Ƿ� ��� ������ ���ؼ� dfs�� ������ �湮�ϴ� �������� +1�� ���ָ�, 
	cnt�� N-1�� �������� ������ �����ϴ� ������ �ȴ�.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);
vector<int> adj[101];
int cnt[101];
void dfs(int u, int root) {
	if (u != root) cnt[u]++;
	for (int v : adj[u]) {
		dfs(v, root);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		dfs(i, i);
	}
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == N - 1) return cout << i, 0;
	}
	cout << -1;
}