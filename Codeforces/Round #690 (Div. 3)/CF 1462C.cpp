/* [CF 1462C] Unique Number
	Algorithm : Greedy

	�� �ڸ����� ���� ������ ���¿��� ���� �������� ���ؾ� �ϹǷ�, 
	���� �ڸ����� ä�� �� �ִ� ���� ū ������ ä��������. 
	ä���� ���ϴ� ��쿡�� -1�� ����Ѵ�.
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
