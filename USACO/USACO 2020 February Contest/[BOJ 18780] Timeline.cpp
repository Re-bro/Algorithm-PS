/* [BOJ 18780] Timeline
	Algorithm : Topological sort

	우선, 각 세션은 적어도 s[i]은 되어야 출석이 가능하다.
	그리고 각 세션은 이전에 반드시 들어야하는 세션이 있기 때문에 
	위상정렬을 이용하여 각 세션을 들을 수 있는 시간을 계산한다. 
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