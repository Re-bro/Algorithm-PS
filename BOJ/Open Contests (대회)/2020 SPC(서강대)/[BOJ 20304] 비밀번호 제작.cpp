/* [BOJ 20304] ��й�ȣ ����
	Algorithm : Bitmask / BFS

	N�� 100�� �����̹Ƿ�, �� ������ �ϳ��� �����̶�� �����Ѵ�.
	�׸���, �־����� ��й�ȣ ���� �ش��ϴ� ������ dis[i] = 0���� �ΰ�, 
	xor���� ��, �ϳ��� bit�� ������ �Ǵ� ������� �̵��ϸ鼭 �Ÿ��� �����س�����.
	�׷��� �� ������ ����ġ�� 1�� �ȴ�. 
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