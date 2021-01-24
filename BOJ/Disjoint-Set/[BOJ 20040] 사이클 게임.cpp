/* [BOJ 20040] 사이클 게임
	Algorithm : Disjoint-set

	정점들을 계속해서 연결해주다가, 이미 같은 집합에 속한 두 정점이 들어오는 경우
	사이클이 만들어진다.
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;

int P[500001];
int find(int a) {
	if (P[a] < 0) return a;
	else return P[a] = find(P[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (P[a] > P[b]) swap(a, b);
		P[a] += P[b];
		P[b] = a;
		return true;
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	ini(P, -1);
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		if (!merge(a, b)) return cout << i, 0;
	}
	cout << 0;
}