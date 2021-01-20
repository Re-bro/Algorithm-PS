/* [BOJ 14908] 구두 수선공
	Algorithm : Greedy / Sort

	S / T 가 큰 값부터 선택해주면 된다. 
	..... i j .... 의 순서가 있고, ..... j i .... 의 순서가 있을 때, 
	전자가 답이 되기 위해서는 k*s[i] + (k + t[i])*s[j] < k*s[j] + (k + t[j])*s[i] 를 만족해야 한다.
	이는 t[i]s[j] < t[j]s[i]와 같고, 결국 s[i]/t[i] > s[j]/t[j]를 만족해야 한다. 
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
bool cmp(tuple<int, int, int> x, tuple<int, int, int> y) {
	auto[a1, b1, c1] = x;
	auto[a2, b2, c2] = y;
	if (a2*b1 == a1*b2) return c1 < c2;
	else return a2*b1 > a1*b2;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<tuple<int, int, int>> v;
	for (int i = 1; i <= n; i++) {
		int t, s; cin >> t >> s;
		v.push_back(make_tuple(t, s, i));
	}
	sort(all(v), cmp);
	for (auto a : v) {
		cout << get<2>(a) << ' ';
	}
}