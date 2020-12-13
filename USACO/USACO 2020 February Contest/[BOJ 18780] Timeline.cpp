/* [BOJ 18780] Timeline
	Algorithm : Topological sort

	�켱, �� ������ ��� s[i]�� �Ǿ�� �⼮�� �����ϴ�.
	�׸��� �� ������ ������ �ݵ�� �����ϴ� ������ �ֱ� ������ 
	���������� �̿��Ͽ� �� ������ ���� �� �ִ� �ð��� ����Ѵ�. 
*/

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int s[100001];
int dis[100001];
int in[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M, C; cin >> N >> M >> C;
	for (int i = 1; i <= N; i++) cin >> s[i];
	vector<vector<pii>> adj(N + 1, vector<pii>());
	for (int i = 1; i <= C; i++) {
		int a, b, x; cin >> a >> b >> x;
		adj[a].push_back({ b, x });
		in[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
		dis[i] = s[i];
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (pii v : adj[u]) {
			dis[v.first] = max(dis[v.first], dis[u] + v.second);
			in[v.first]--;
			if (in[v.first] == 0) q.push(v.first);
		}
	}
	for (int i = 1; i <= N; i++) cout<<dis[i]<<'\n';
}