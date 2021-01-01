/* [BOJ 10244] 최대공약수들
	Algorithm : Euclidean Algorithm / Brute-force

	A[i]의 범위가 1이상 100이하이므로 나올 수 있는 최대공약수의 범위또한 1이상 100이하이다.
	따라서 완전탐색으로 k = 1부터 100까지 탐색하면서, 최대 공약수로 k가 나올 수 있는지를 체크한다.
	만약 A[i]가 k이면 [i, i] 구간을 잡으면 가능하고, A[i]를 포함시켰을 때 k보다 작아지면 
	A[i]가 포함된 구간은 불가능하다.
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