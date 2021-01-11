/* [CF 1154B] Make Them Equal
	Algorithm : Brute-force

	어떤 음이 아닌 정수 D로 배열의 각 원소를 더하거나, 빼거나, 그대로 둘 때 
	모든 원소를 동일하게 만들 수 있다면 그 가능한 D중 최솟값을 찾는 문제이다.
	배열의 원소들의 범위가 작으므로 완전탐색으로 배열의 원소가 k로 같다면 
	이를 만들 수 있는 D가 존재하는지를 찾는다.
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;

int A[101];
int cnt[301];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int ans = 100000;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = -100; i <= 200; i++) {
		ini(cnt, 0);
		for (int j = 1; j <= n; j++) {
			cnt[abs(A[j] - i)]++;
		}
		int k = 0;
		for (int i = 1; i <= 300; i++) {
			if (cnt[i] > 0) k++;
		}
		if (k <= 1) {
			int tmp = 0;
			for (int j = 1; j <= n; j++) {
				tmp = max(tmp, abs(A[j] - i));
			}
			ans = min(ans, tmp);
		}
	}
	if (ans == 100000) cout << -1;
	else cout << ans;
}