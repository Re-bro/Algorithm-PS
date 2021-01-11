/* [BOJ 1289] 트리의 가중치
	Algorithm : Tree DP

	현재 노드를 u라고 하고, 자식들을 v1, v2, ..., vk 라고 하자. 
	u를 루트로 하는 서브트리에서의 트리의 가중치는 다음과 같다. 
	1. 모든 i에 대해서 (u, vi)의 가중치의 합
	2. 모든 i에 대해서 "vi를 루트로 하는 서브트리에서 vi를 끝으로 하는 모든 경로 * (u, v1)의 가중치"의 합
	3. 모든 i, j에 대해서 "vi를 루트로 하는 서브트리의 노드에서 vj를 루트로 하는 서브트리의 노드까지의 경로의 가중치의 합 
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

vector<pii> adj[100001];
ll ans;
ll dfs(int u, int p) {
	ll res = 0;
	ll tmp = 0;
	for (pll v : adj[u]) {
		if (v.first == p) continue;
		ll k = dfs(v.first, u);
		res += k * v.second % MOD + v.second;
		res %= MOD;
		if (tmp == 0) {
			tmp += k * v.second % MOD + v.second;
		}
		else {
			ans += (tmp * (k * v.second % MOD + v.second)) % MOD;
			ans %= MOD;
			tmp += k * v.second % MOD + v.second;
			tmp %= MOD;
		}
	}
	ans += res;
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	dfs(1, 1);
	ans %= MOD;
	cout << ans;
}