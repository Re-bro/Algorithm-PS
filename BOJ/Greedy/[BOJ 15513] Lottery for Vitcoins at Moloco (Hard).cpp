/* [BOJ 15513] Lottery for Vitcoins at Moloco (Hard)
	Algorithm : Greedy / Sorting

	(1-p)/w가 작은 순서대로 정렬하면 된다. 
	.....i , j, ..... 와 .....j, i, ...... 에 대한 결과 식을 각각 세워서 부등식을 만들어주면 알 수 있다.
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