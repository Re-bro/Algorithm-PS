/* [BOJ 20304] 비밀번호 제작
	Algorithm : Bitmask / BFS

	N이 100만 이하이므로, 각 수마다 하나의 정점이라고 생각한다.
	그리고, 주어지는 비밀번호 값에 해당하는 정점은 dis[i] = 0으로 두고, 
	xor했을 때, 하나의 bit만 켜지게 되는 정점들로 이동하면서 거리를 갱신해나간다.
	그러면 각 간선의 가중치는 1이 된다. 
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e9;
int dis[1000001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	int M; cin >> M;
	fill(dis, dis + N + 1, MAX);
	queue<int> q;
	for (int i = 1; i <= M; i++) {
		int a; cin >> a;
		dis[a] = 0;
		q.push(a);
	}
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < 20; i++) {
			int next = now ^ (1 << i);
			if (next >N || dis[next] != MAX) continue;
			dis[next] = dis[now] + 1;
			q.push(next);
		}
	}
	int ans = 0;
	for (int i = 0; i <= N; i++) {
		ans = max(ans, dis[i]);
	}
	cout << ans;
}