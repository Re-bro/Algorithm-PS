/* [BOJ 17455] kdh9949
	Algorithm : Tree DP

	����, �׷����� ������ �� k->d, d->h, h->k �� ������ �����Ų��.
	�׸���, �ش� �׷������� ����Ŭ�� �ִ� ��쿡�� ���� -1�̴�.
	����Ŭ�� ���ٸ� DAG�� �ǰ�, �ᱹ Tree dp�� ������ ������ �ȴ�. 
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
const int MAX = (int)2e9;

int ch[200001];
vector<int> adj[200001];
int dp[200001];
bool cycle[200001];
bool visited[200001];
int sol(int u) {
	if (visited[u] || cycle[u]) {
		cycle[u] = true;
		return MAX;
	}
	int &ret = dp[u];
	if (ret != -1) return ret;
	ret = 1;
	visited[u] = true;
	for (int v : adj[u]) {
		if (ch[v] == (ch[u] + 1) % 3) ret = max(ret, sol(v)+1);
		if (ret >= MAX) {
			cycle[u] = true;
			break;
		}
	}
	visited[u] = false;
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N, M; cin >> N >> M;
	string s; cin >> s;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'K') ch[i + 1] = 0;
		else if (s[i] == 'D') ch[i + 1] = 1;
		else ch[i + 1] = 2;
	}
	ini(dp, -1);
	for (int i = 1; i <= M; i++) {
		int a, b; cin >> a >> b;
		if((ch[a]+1)%3 == ch[b]) adj[a].push_back(b);
		if((ch[b]+1)%3 == ch[a]) adj[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (ch[i] == 0) ans = max(ans, (sol(i)/3)*3);
	}
	if (ans >= 1000000 || ans == 0) cout << -1;
	else	cout << ans;
}