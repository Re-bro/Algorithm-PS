/* [BOJ 18786] Triangles (Bronze)
	Algorithm : Brute-force

	만들 수 있는 직각삼각형중 최대 넓이를 구하는 문제이다. 
	x축과 y축에 각각 평행한 변이 1개씩 있어야 한다.
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