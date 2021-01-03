/* [CF 1257E] The Contest
	Algorithm : DP

	1, 2, 3으로 이루어진 수열이 주어질 때, 1....12....23...3 과 같이 만들어주기 위한 최소 변경 횟수를 구하는 문제이다.
	즉, 같은 숫자끼리는 항상 이웃해야하고 오름차순을 만족해야 한다는 의미이다.
	여기서 반드시 1,2,3이 모두 나올 필요는 없다.
	dp[i][j] = A[i] = j이면서 문제 조건을 만족하는 i번째 원소까지의 최소 변경 횟수라고 하면,
	dp[i][1]은 앞에 항상 1이 와야하므로 dp[i-1][1]을 가져오고,
	dp[i][2]는 앞에 1 또는 2가 올 수 있으므로 dp[i-1][1], dp[i-1][2]를 가져오고,
	dp[i][3]은 앞에 어떤 수가 와도 상관없으므로 dp[i-1][1], dp[i-1][2], dp[i-1][3] 모두 가져온다.
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;

int num[200001];
int dp[200001][4];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int k1, k2, k3; cin >> k1 >> k2 >> k3;
	int n = k1 + k2 + k3;
	for (int i = 1; i <= k1; i++) {
		int a; cin >> a;
		num[a] = 1;
	}
	for (int i = 1; i <= k2; i++) {
		int a; cin >> a;
		num[a] = 2;
	}
	for (int i = 1; i <= k3; i++) {
		int a; cin >> a;
		num[a] = 3;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			dp[i][j] = MAX;
			for (int k = 1; k <= j; k++) {
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + (j != num[i] ? 1 : 0));
			}
		}
	}
	cout << min({ dp[n][1], dp[n][2], dp[n][3] });
}