/* [BOJ 3747] 완벽한 선거!
	Algorithm : 2-SAT

	전형적인 2-SAT 문제. 입력만 조금 까다롭다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);

vector<vector<int>>adj;
int sn[2001], dfs_n[2001], SN, cnt;
stack<int> S;
int dfs(int u) {
	dfs_n[u] = ++cnt;
	int ret = dfs_n[u];
	S.push(u);
	for (int v : adj[u]) {
		if (dfs_n[v] == 0) ret = min(ret, dfs(v));
		else if (sn[v] == -1) ret = min(ret, dfs_n[v]);
	}
	if (ret == dfs_n[u]) {
		while (1) {
			int k = S.top(); S.pop();
			sn[k] = SN;
			if (k == u) break;
		}
		SN++;
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N, M;
	while (cin >> N) {
		SN = cnt = 0;
		ini(sn, -1);
		ini(dfs_n, 0);
		cin >> M;
		adj.assign(2 * N + 1, vector<int>());
		string s1, s2;
		for (int i = 1; i <= M; i++) {
			cin >> s1 >> s2;
			int a = 0;
			int b = 0;
			for (int j = 1; j < sz(s1); j++) {
				a *= 10;
				a += s1[j] - '0';
			}
			for (int j = 1; j < sz(s2); j++) {
				b *= 10;
				b += s2[j] - '0';
			}
			a = (s1[0] == '+') ? a * 2 - 1 : a * 2;
			b = (s2[0] == '+') ? b * 2 - 1 : b * 2;
			if (a % 2) adj[a + 1].push_back(b);
			else adj[a - 1].push_back(b);
			if (b % 2) adj[b + 1].push_back(a);
			else adj[b - 1].push_back(a);
		}
		for (int i = 1; i <= 2 * N; i++) if (dfs_n[i] == 0) dfs(i);
		bool chk = true;
		for (int i = 1; i <= 2 * N; i++) {
			if (sn[i] == sn[i + 1]) chk = false;
		}
		if (chk) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}
