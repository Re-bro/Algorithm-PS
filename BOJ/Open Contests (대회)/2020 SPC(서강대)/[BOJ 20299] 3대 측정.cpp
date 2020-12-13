/* [BOJ 20299] 3대 측정
	Algorithm : Implementation

	풀이 : https://wogud6792.tistory.com/78
*/


#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N, K, L; cin >> N >> K >> L;
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a + b + c >= K && a >= L && b >= L && c >= L) {
			v.push_back(a);
			v.push_back(b);
			v.push_back(c);
		}
	}
	cout << sz(v) / 3 << '\n';
	for (int a : v) cout << a << ' ';
}