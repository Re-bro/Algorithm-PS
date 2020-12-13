/* [BOJ 18788] Swapity Swap
	Algorithm : Brute-force

	N의 제한이 작고, swap이 각 단계별로 두번밖에 진행되지 않으므로, 
	완전탐색으로 시간내에 다시 처음 배열로 돌아오는 횟수를 찾을 수 있다.
	그러면 K를 횟수로 나눈 나머지만큼만 반복하면 답이 나온다.

*/

#include<bits/stdc++.h>
using namespace std;
int main(void) {
	int N, K, a1, a2, b1, b2; cin >> N >> K >> a1 >> a2 >> b1 >> b2;
	int A[101];
	for (int i = 1; i <= N; i++) A[i] = i;
	int cnt = K;
	while (cnt--) {
		reverse(A + a1, A + a2 + 1);
		reverse(A + b1, A+ b2 + 1);
		bool chk = true;
		for (int i = 1; i <= N; i++) {
			if (A[i] != i) chk = false;
		}
		if (chk) {
			cnt = K % (K - cnt);
		}
	}
	for (int i = 1; i <= N; i++) cout << A[i] << '\n';
}