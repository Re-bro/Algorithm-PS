/* [CF 1461B] Find the Spruce
	Algorithm : DP

	(i, j) �� ���� �� �簢���̸鼭, ���� ������� �ѻ����� �� ū ������ �����ϱ� ���ؼ���
	(i+1, j-1), (i+1, j), (i+1, j+1)�� ���� �� �簢������ �ϴ� ������ ������ �����ؾ� �Ѵ�. 
	�׷��Ƿ� while���� ���ؼ� �� ������� �̸� �����ϴ� ��찡 �����ϴ��� üũ�ϰ�, 
	�����Ѵٸ� dp[i][j]++�� ���־� (i,j)�� �� �簢������ �ϴ� ������ ������ ���������ش�. 
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