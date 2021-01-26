/* [BOJ 13306] Ʈ��
	Algorithm : Disjoint-set / Offline query

	Ʈ���� ������ �����ϴ� ����� �ƴ϶�, �Ųٷ� ������ ���鼭
	������ �߰��ϴ� ������� �����ϸ� �ȴ�. 
	���� �̰������� Union-find ����� �̿�ȴ�.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
int n, q;
int P[200001];
int find(int a) {
	return (P[a] < 0 ? a : P[a] = find(P[a]));
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
	cin >> n >> q;
	for (int i = 2; i <= n; i++) cin >> P[i];
	vector<tuple<int, int, int>> query;
	for (int i = 1; i <= n+q-1; i++) {
		int x; cin >> x;
		int a, b;
		if (x == 0) {
			cin >> a;
			b = P[a];
		}
		else cin >> a >> b;
		query.push_back(make_tuple(x, a, b));
	}
	ini(P, -1);
	reverse(all(query));
	vector<int> ans;
	for (auto[x, a, b] : query) {
		if (x == 0) 	merge(a, b);
		else {
			if (find(a) == find(b)) {
				ans.push_back(1);
			}
			else ans.push_back(0);
		}
	}
	reverse(all(ans));
	for (int i : ans) {
		cout << (i ? "YES\n" : "NO\n");
	}
}