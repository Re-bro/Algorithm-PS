/* Round #686 (Div. 3) E
	Algorithm : dfs / tree / graphs
	
	�� ���� �׷����� ������ ������ n���̰�, ������ ������ n-1���̸� Ʈ���� �����Ѵ�.
	�׷��Ƿ� ������ ������ n���̸� ������ Ʈ���� ������ �ϳ��� �߰��Ǿ� ����Ŭ�� �ϳ��� �����ϴ� ���°� ���´�.
	�̸� ����Ŭ �ϳ���, ����Ŭ�� �̷�� �����鿡 Ʈ���� �پ��ִ� �� ó�� �����Ѵ�.
	�׷��� �� Ʈ������ ���ο��� ����� path���, Ʈ���� Ʈ�����̸� �����ϴ� path�� ����������. 
	Ʈ���� ������ ��쿡�� ������ ������ a���̸� 1 + 2 + ... + a-1 = a*(a-1)/2 ���� path�� �����Ѵ�.
	�� Ʈ������ �ٸ� Ʈ���� ����Ǵ� path�� Ʈ���� ���� a���� �ϳ���, 
	�ٸ� Ʈ���� ���� n-a�� �� �ϳ��� ���� ����� ���� ����.

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

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int>in(n + 1, 0), visited(n+1, 0);
		vector<vector<int>>adj(n + 1, vector<int>());
		for (int i = 1; i <= n; i++) {
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			in[a]++;
			in[b]++;
		}
		vector<int> cnt(n+1, 1);
		queue<int> leaf;
		for (int i = 1; i <= n; i++) {
			if (in[i] == 1) leaf.push(i);
		}
		while (!leaf.empty()){
			int v = leaf.front(); leaf.pop();
			visited[v] = true;
			for (int u : adj[v]) {
				if (visited[u]) continue;
				cnt[u] += cnt[v];
				cnt[v] = 0;
				in[u]--;
				if (in[u] == 1) leaf.push(u);
			}
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
			ans += 1LL * cnt[i] * (n - cnt[i]);
		}
		cout << ans << '\n';
	}
}