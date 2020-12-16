/* [CF 1462D] Add to Neighbour and Remove
	Algorithm : prefix sum / Brute-force

	배열의 누적합을 pre[i]라고 하면, 원소가 모두 같게 만들었을 때
	해당 원소의 값은 반드시 pre[1], pre[2] , ..., pre[n]중의 하나가 되어야 한다.
	문제에서 주어진 연산을 어떻게, 몇번을 적용하던지
	항상 배열의 제일 처음 원소는 pre[i] 값 중 하나로 나오기 때문이다.
	따라서 pre[1] ~ pre[n]의 값중 하나로 배열의 모든 원소를 바꿀 수 있는지를 체크하고, 
	그 중 가장 적은 연산 수를 구한다.
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