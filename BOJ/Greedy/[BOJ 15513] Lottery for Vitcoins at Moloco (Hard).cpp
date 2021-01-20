/* [BOJ 15513] Lottery for Vitcoins at Moloco (Hard)
	Algorithm : Greedy / Sorting

	(1-p)/w�� ���� ������� �����ϸ� �ȴ�. 
	.....i , j, ..... �� .....j, i, ...... �� ���� ��� ���� ���� ������ �ε���� ������ָ� �� �� �ִ�.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	auto [i, j, k] = a;
	auto [x, y, z] = b;
	int k1 = (10000 - j) * x;
	int k2 = (10000 - y) * i;
	if (k1 == k2) return k < z;
	return k1 < k2;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<tuple<int, int, int>> v;
	for (int i = 0; i < n; i++) {
		int w, q; cin >> w >> q;
		v.push_back(make_tuple(w, q, i+1));
	}
	sort(all(v), cmp);
	for (auto [a, b, c] : v) {
		cout << c << ' ';
	}
}