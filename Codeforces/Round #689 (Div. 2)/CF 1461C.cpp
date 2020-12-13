/* [CF 1461C] Random Events
	Algorithm : DP

	현재까지 시행했을 때, 성공할 확률을 계속해서 구해나간다.
	만약 r만큼 정렬을 해도 오름차순이 안되는 경우에는 확률이 0이므로 무시한다.
	지금까지 성공했다면, 그 이후에는 가만히 유지시켜도 되므로 
	i-1번째 시행까지 했을 때의 확률을 A[i-1]라고 한다면,
	A[i] = A[i-1]*(1-p) + p 를 만족한다. 
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