/* [BOJ 18788] Swapity Swap
	Algorithm : Brute-force

	N�� ������ �۰�, swap�� �� �ܰ躰�� �ι��ۿ� ������� �����Ƿ�, 
	����Ž������ �ð����� �ٽ� ó�� �迭�� ���ƿ��� Ƚ���� ã�� �� �ִ�.
	�׷��� K�� Ƚ���� ���� ��������ŭ�� �ݺ��ϸ� ���� ���´�.

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