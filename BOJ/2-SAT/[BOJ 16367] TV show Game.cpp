/* [BOJ 16367] TV Show Game
	Algorithm : 2-SAT

	2-SAT ������ ��������̴�. 
	�� �� �ϳ��� �����ϴ� ���� �����ʹ� �ٸ��� �� ������
	3�� �� �� �� �̻��� �����ؾ� �Ѵ�. 
	���� �� A, B, C �� 2�� �̻��� �����ϱ� ���ؼ� 2-SAT���� ��Ÿ���ٸ�
	(A || B) && (B || C) && (A || C)�� �����ؾ� �Ѵ�. 
	���� ������ �����ϴ�.
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
int dfs_n[10001], sn[10001], SN, cnt;
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
	int k, n; cin >> k >> n;
	adj.assign(2 * k + 1, vector<int>());
	for (int i = 1; i <= n; i++) {
		int a, b, c; char d, e, f;
		cin >> a >> d >> b >> e >> c >> f;
		a = (d == 'R') ? a * 2 - 1 : a * 2;
		b = (e == 'R') ? b * 2 - 1 : b * 2;
		c = (f == 'R') ? c * 2 - 1 : c * 2;
		int k;
		for (int j = 1; j <= 3; j++) {
			if (j == 1) k = a;
			else if (j == 2) k = b;
			else k = c;
			if (k % 2) {
				if (k != a) adj[k + 1].push_back(a);
				if (k != b) adj[k + 1].push_back(b);
				if (k != c) adj[k + 1].push_back(c);
			}
			else {
				if (k != a) adj[k - 1].push_back(a);
				if (k != b) adj[k - 1].push_back(b);
				if (k != c) adj[k - 1].push_back(c);
			}
		}
	}
	ini(sn, -1);
	for (int i = 1; i <= 2 * k; i++) if (dfs_n[i] == 0) dfs(i);
	string ans = "";
	for (int i = 1; i <= 2 * k; i+=2) {
		if (sn[i] == sn[i + 1]) {
			cout << -1;
			return 0;
		}
		ans += (sn[i] < sn[i + 1]) ? 'R' : 'B';
	}
	cout << ans;
	
}
