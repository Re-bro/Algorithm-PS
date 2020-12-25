/* [BOJ 14621] ���� �ȵǴ� ����
	Algorithm : minimum spanning tree

	��� �������� ��Ƴ���, �Ÿ��� ª�� �������� �����س�����.
	�� ��, ���� ���б��� ���� ���б��� ����� ������ ������ش�. 
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using pii = pair<int, int>;
bool sex[1001];
int P[1001];
int find(int a) {
	return P[a] < 0 ? a : (P[a] = find(P[a]));
}
bool merge(int a, int b) {
	if (sex[a] == sex[b]) return false;
	a = find(a);
	b = find(b);
	if (a == b) return false;
	else {
		if (P[a] > P[b]) swap(a, b);
		P[a] += P[b];
		P[b] = a;
		return true;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		char c; cin >> c;
		if (c == 'M') sex[i] = 1;
	}
	ini(P, -1);
	priority_queue<pair<int, pii>> pq;
	for (int i = 1; i <= M; i++) {
		int u, v, d; cin >> u >> v >> d;
		pq.push({ -d, {u, v} });
	}
	int ans = 0;
	while (!pq.empty()) {
		if (merge(pq.top().second.first, pq.top().second.second)) {
			ans += -pq.top().first;
		}
		pq.pop();
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (P[i] < 0) cnt++;
	}
	if (cnt == 1) cout << ans;
	else cout << -1;
}