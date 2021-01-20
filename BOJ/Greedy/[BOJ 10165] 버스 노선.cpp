/* [BOJ 10165] ���� �뼱
	Algorithm : Greedy / Sorting

	a > b�� �뼱�� ��쿡�� b�� +n�� ���־ ���� �������·� Ǯ���� �� �ְ� �����.
	��, b+n�� ���� ��, ���� ���ÿ����� 5���� 1���� �����ϴ� ���� ������� ���Ѵ�.
	�̷� ���� ���� �뼱 �� ���� �� �뼱�� ���������� 0�� �ǵ��� �� �����뼱���� ��ġ�� ���� �������ָ�
	���� �� �뼱�� �׻� �ٸ� �뼱�� ���Ե� �� �����Ƿ�, �ڿ������� ���� ���ܵ��� ������ �ʴ´�. 

	� �뼱 x�� �뼱 y�� ���Եȴٸ� x.a >= y.a && x.b <=y.b�� �����ؾ��ϹǷ� 
	�������� ���ؼ� Ǯ���ش�.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using pii = pair<int, int>;
bool cmp(tuple<int, int, int> x, tuple<int, int, int> y) {
	auto [a, b, c] = x;
	auto [d, e, f] = y;
	if (b == e) return a > d;
	else return b < e;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<tuple<int, int, int>>v;
	int mx = 0;
	int s;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		v.push_back(make_tuple(a, b, i));
		if (a > b) {
			if (mx < b + n - a) {
				mx = b + n - a;
				s = a;
			}
		}
		else {
			if (mx < b - a) {
				mx = b - a;
				s = a;
			}
		}
	}
	for (auto& [a, b, c] : v) {
		a = (a + n - s) % n;
		b = (b + n - s) % n;
		if (a > b) b += n;
	}
	sort(all(v), cmp);
	priority_queue<pii> pq;
	for (auto [a, b, c] : v) {
		while (!pq.empty() && pq.top().first >= a) pq.pop();
		pq.push({ a, c });
	}
	vector<int> ans;
	while (!pq.empty()) {
		ans.push_back(pq.top().second);
		pq.pop();
	}
	sort(all(ans));
	for (int i : ans) cout << i << ' ';
}