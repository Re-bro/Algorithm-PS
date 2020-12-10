/* [BOJ 18786] Triangles (Bronze)
	Algorithm : Brute-force

	���� �� �ִ� �����ﰢ���� �ִ� ���̸� ���ϴ� �����̴�. 
	x��� y�࿡ ���� ������ ���� 1���� �־�� �Ѵ�.
*/

#include<bits/stdc++.h>
using namespace std;

int A[101][2];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i][0] >> A[i][1];
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (A[i][0] == A[j][0]) {
				for (int k = 1; k <= N; k++) {
					if (k != i && k != j && (A[k][1] == A[i][1] || A[k][1] == A[j][1])) ans = max(ans, abs(A[i][1] - A[j][1])*abs(A[i][0] - A[k][0]));
				}
			}
			if (A[i][1] == A[j][1]) {
				for (int k = 1; k <= N; k++) {
					if (k != i && k != j && (A[k][0] == A[i][0] || A[k][0] == A[j][0])) ans = max(ans, abs(A[i][0] - A[j][0])* abs(A[i][1] - A[k][1]));
				}
			}
		}
	}
	cout << ans;
}