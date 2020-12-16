/* [CF 1462C] Unique Number
	Algorithm : Greedy

	각 자릿수의 합이 고정된 상태에서 가장 작은수를 구해야 하므로, 
	일의 자리부터 채울 수 있는 가장 큰 값으로 채워나간다. 
	채우지 못하는 경우에는 -1을 출력한다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int x; cin >> x;
		vector<int> ans;
		for (int i = 9; i >= 1; i--) {
			if (i <= x) {
				ans.push_back(i);
				x -= i;
			}
			else continue;
		}
		if (x != 0) cout << -1 << '\n';
		else {
			reverse(all(ans));
			for (int i : ans)cout << i;
			cout << '\n';
		}
	}
}
