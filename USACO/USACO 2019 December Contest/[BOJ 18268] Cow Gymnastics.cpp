/* [BOJ 18268] Cow Gymnastics
	Algorithm : Brute-force

	입력이 소별 등수가 아니라, 등수 순서대로 소의 번호가 들어오는 점에 유의하자.
	N과 K의 범위가 작으므로 완전 탐색으로 현재 소보다 등수가 모두 작은 소의 수를 세면 된다.
*/

#include<bits/stdc++.h>
using namespace std;
int A[21][11];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int K, N; cin >> K >> N;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			int a; cin >> a;
			A[a][i] = j;
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			bool chk = true;
			for (int k = 1; k <= K; k++) {
				if (A[i][k] <= A[j][k]) chk = false;
			}
			if (chk) ans++;
		}
	}
	cout << ans;
}