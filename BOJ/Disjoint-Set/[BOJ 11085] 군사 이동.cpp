/* [BOJ 11085] ���� �̵�
	Algorithm : Disjoint-set

	���� �ʺ��� �ּҸ� �ִ�ȭ�ϴ� �����̹Ƿ�, 
	���� �ʺ� ���� ū �ͺ��� �����ذ��鼭 c�� v�� ����Ǵ����� Ȯ���Ѵ�. 
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
int P[1001];
int find(int a) {
	return P[a] < 0 ? a : P[a] = find(P[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (P[a] > P[b]) swap(a, b);
		P[a] += P[b];
		P[b] = a;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int p, w; cin >> p >> w;
	int c, v; cin >> c >> v;
	ini(P, -1);
	vector<tuple<int, int, int>> edge;
	for (int i = 1; i <= w; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge.push_back(make_tuple(-c, a, b));
	}
	sort(all(edge));
	for (auto[k, a, b] : edge) {
		k = -k;
		merge(a, b);
		if (find(c) == find(v)) {
			return cout << k, 0;
		}
	}
}