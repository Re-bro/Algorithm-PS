/* [BOJ 17619] ������ ����
	Algorithm : Disjoint-set
	
	���� ���� ���� ������� ������ �����Ѵ�. 
	���������� ������ �� ������ ��ġ�� ���� ū ���� (lastidx) �� �����صΰ�,
	���� ������ [l, r]�̶�� �ϸ�, lastidx�� ���� ���� �ݵ�� l���� �۰ų� ���� ������
	l�� lastidx�� �������� ���ʿ� ������ �� ������ ��ġ�� ���̹Ƿ� merge(lastidx, i)�� ���ش�.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
using pii = pair<int, int>;
int P[100001];
int find(int a) {
	if (P[a] < 0) return a;
	else return P[a] = find(P[a]);
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
	int n, q; cin >> n >> q;
	ini(P, -1);
	vector<pair<pii, int>>v;
	for (int i = 1; i <= n; i++) {
		int x1, x2, y; cin >> x1 >> x2 >> y;
		v.push_back({ { x1, x2 }, i });
	}
	sort(all(v));
	int last = v[0].first.second;
	int lastidx = v[0].second;
	for (int i = 1; i < n; i++) {
		if (last >= v[i].first.first) merge(lastidx, v[i].second);
		if (last < v[i].first.second) {
			last = v[i].first.second;
			lastidx = v[i].second;
		}
	}
	while (q--) {
		int a, b; cin >> a >> b;
		if (find(a) == find(b)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}