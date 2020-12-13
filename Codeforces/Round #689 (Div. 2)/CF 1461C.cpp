/* [CF 1461C] Random Events
	Algorithm : DP

	������� �������� ��, ������ Ȯ���� ����ؼ� ���س�����.
	���� r��ŭ ������ �ص� ���������� �ȵǴ� ��쿡�� Ȯ���� 0�̹Ƿ� �����Ѵ�.
	���ݱ��� �����ߴٸ�, �� ���Ŀ��� ������ �������ѵ� �ǹǷ� 
	i-1��° ������� ���� ���� Ȯ���� A[i-1]��� �Ѵٸ�,
	A[i] = A[i-1]*(1-p) + p �� �����Ѵ�. 
*/

#include<bits/stdc++.h>
using namespace std;
int A[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> A[i];
		int idx = 200000;
		for (int i = n; i >= 1; i--) {
			if (A[i] != i) {
				idx = i;
				break;
			}
		}
		double ans = 0;
		for (int i = 1; i <= m; i++) {
			int r; cin >> r;
			double p; cin >> p;
			if (r >= idx) {
				ans *= (1.0 - p);
				ans += p;
			}
		}
		cout << fixed;
		cout.precision(10);
		if (idx == 200000) ans = 1;
		cout << ans << '\n';

	}
}