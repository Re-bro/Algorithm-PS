/* [CF 1257A] Two Rival Students
	Algorithm : Implementation

	수직선상에 두 사람이 서있고, 한번 작업을 수행하면 두 사람의 거리를 1만큼 더 멀게 할 수 있다.
	최대 x번 작업을 수행할 수 있으므로, 멀어질 수 있을 만큼 최대한 이동시켜준다.
*/

#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, x, a, b; cin >> n >> x >> a >> b;
		if (a > b) swap(a, b);
		cout << min(n-1, b - a + x) << '\n';
	}
}