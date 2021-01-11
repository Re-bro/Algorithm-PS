/* [BOJ 1289] Ʈ���� ����ġ
	Algorithm : Tree DP

	���� ��带 u��� �ϰ�, �ڽĵ��� v1, v2, ..., vk ��� ����. 
	u�� ��Ʈ�� �ϴ� ����Ʈ�������� Ʈ���� ����ġ�� ������ ����. 
	1. ��� i�� ���ؼ� (u, vi)�� ����ġ�� ��
	2. ��� i�� ���ؼ� "vi�� ��Ʈ�� �ϴ� ����Ʈ������ vi�� ������ �ϴ� ��� ��� * (u, v1)�� ����ġ"�� ��
	3. ��� i, j�� ���ؼ� "vi�� ��Ʈ�� �ϴ� ����Ʈ���� ��忡�� vj�� ��Ʈ�� �ϴ� ����Ʈ���� �������� ����� ����ġ�� �� 
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