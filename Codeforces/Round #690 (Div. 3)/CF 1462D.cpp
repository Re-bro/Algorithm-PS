/* [CF 1462D] Add to Neighbour and Remove
	Algorithm : prefix sum / Brute-force

	�迭�� �������� pre[i]��� �ϸ�, ���Ұ� ��� ���� ������� ��
	�ش� ������ ���� �ݵ�� pre[1], pre[2] , ..., pre[n]���� �ϳ��� �Ǿ�� �Ѵ�.
	�������� �־��� ������ ���, ����� �����ϴ���
	�׻� �迭�� ���� ó�� ���Ҵ� pre[i] �� �� �ϳ��� ������ �����̴�.
	���� pre[1] ~ pre[n]�� ���� �ϳ��� �迭�� ��� ���Ҹ� �ٲ� �� �ִ����� üũ�ϰ�, 
	�� �� ���� ���� ���� ���� ���Ѵ�.
*/

#include<bits/stdc++.h>
using namespace std;
int A[3001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> A[i];
		int pre = 0;
		int ans = (int)1e9;
		for (int k = 1; k <= n; k++) {
			pre += A[k];
			int cnt = k - 1;
			int tmp = 0;
			bool chk = true;
			for (int i = k + 1; i <= n; i++) {
				if (A[i] == pre) {
					if (tmp != 0) chk = false;
				}
				else if (tmp + A[i] <= pre) {
					if (tmp == 0) tmp += A[i];
					else {
						tmp += A[i];
						cnt++;
					}
					if (tmp == pre) tmp = 0;
				}
				else {
					chk = false;
					break;
				}
			}
			if (tmp != 0) chk = false;
			if (chk) ans = min(ans, cnt);
		}
		cout << ans << '\n';
	}
}