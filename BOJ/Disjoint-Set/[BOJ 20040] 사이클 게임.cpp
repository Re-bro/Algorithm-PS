/* [BOJ 20040] ����Ŭ ����
	Algorithm : Disjoint-set

	�������� ����ؼ� �������ִٰ�, �̹� ���� ���տ� ���� �� ������ ������ ���
	����Ŭ�� ���������.
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