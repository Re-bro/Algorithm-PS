/* Round #686 (Div. 3) E
	Algorithm : dfs / tree / graphs
	
	한 연결 그래프가 정점의 개수가 n개이고, 간선의 개수가 n-1개이면 트리를 만족한다.
	그러므로 간선의 개수가 n개이면 기존의 트리에 간선이 하나가 추가되어 사이클이 하나만 존재하는 형태가 나온다.
	이를 사이클 하나와, 사이클을 이루는 정점들에 트리가 붙어있는 것 처럼 생각한다.
	그러면 각 트리별로 내부에서 생기는 path들과, 트리와 트리사이를 연결하는 path로 나누어진다. 
	트리의 내부인 경우에는 정점의 개수가 a개이면 1 + 2 + ... + a-1 = a*(a-1)/2 개의 path가 존재한다.
	한 트리에서 다른 트리로 연결되는 path는 트리의 정점 a개중 하나와, 
	다른 트리의 정점 n-a개 중 하나를 고르는 경우의 수와 같다.

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