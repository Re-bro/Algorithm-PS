/* [BOJ 18268] Cow Gymnastics
	Algorithm : Brute-force

	�Է��� �Һ� ����� �ƴ϶�, ��� ������� ���� ��ȣ�� ������ ���� ��������.
	N�� K�� ������ �����Ƿ� ���� Ž������ ���� �Һ��� ����� ��� ���� ���� ���� ���� �ȴ�.
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