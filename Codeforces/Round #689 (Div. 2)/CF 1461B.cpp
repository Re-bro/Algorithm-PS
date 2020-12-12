/* [CF 1461B] Find the Spruce
	Algorithm : DP

	(i, j) 가 가장 윗 사각형이면서, 현재 사이즈보다 한사이즈 더 큰 도형이 존재하기 위해서는
	(i+1, j-1), (i+1, j), (i+1, j+1)을 가장 윗 사각형으로 하는 동일한 도형이 존재해야 한다. 
	그러므로 while문을 통해서 각 사이즈별로 이를 만족하는 경우가 존재하는지 체크하고, 
	존재한다면 dp[i][j]++을 해주어 (i,j)를 윗 사각형으로 하는 도형의 개수를 증가시켜준다. 
*/

#include<bits/stdc++.h>
using namespace std;
int A[501][501];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		vector<string> v(n);
		memset(A, 0, sizeof(A));
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			for (int j = 0; j < m; j++) {
				if (v[i][j] == '*') A[i + 1][j + 1] = 1;
			}
		}
		int k = 1;
		while (1) {
			int cnt = 0;
			for (int i = 1; i < n; i++) {
				for (int j = 2; j < m; j++) {
					if (A[i][j] == k && A[i + 1][j - 1] == k && A[i + 1][j] == k && A[i + 1][j + 1] == k) {
						A[i][j] = k + 1;
						cnt++;
					}
				}
			}
			if (cnt < 4) break;
			k++;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) ans += A[i][j];
		}
		cout << ans << '\n';
	}
}