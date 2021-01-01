/* [BOJ 10244] �ִ�������
	Algorithm : Euclidean Algorithm / Brute-force

	A[i]�� ������ 1�̻� 100�����̹Ƿ� ���� �� �ִ� �ִ������� �������� 1�̻� 100�����̴�.
	���� ����Ž������ k = 1���� 100���� Ž���ϸ鼭, �ִ� ������� k�� ���� �� �ִ����� üũ�Ѵ�.
	���� A[i]�� k�̸� [i, i] ������ ������ �����ϰ�, A[i]�� ���Խ����� �� k���� �۾����� 
	A[i]�� ���Ե� ������ �Ұ����ϴ�.
*/

#include<bits/stdc++.h>
using namespace std;
int A[100010];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	while (1) {
		int n; cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++) cin >> A[i];
		int ans = 0;
		int g;
		for (int k = 1; k <= 100; k++) {
			for (int i = 1; i <= n; i++) {
				if (i == 1) g = A[i];
				else g = gcd(g, A[i]);
				if (g == k) {
					ans++;
					break;
				}
				else if (g < k || g % k != 0) {
					g = A[i + 1];
				}
			}
		}
		cout << ans << '\n';
	}
}