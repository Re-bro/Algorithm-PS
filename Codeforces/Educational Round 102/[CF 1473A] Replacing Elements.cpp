/* [CF 1473A] Replacing Elements
	Algorithm : Math

	기본적으로 주어지는 모든 원소가 d 이하이면 아무런 작업을 하지 않아도 된다.
	만약 d보다 큰 원소가 하나 이상 존재한다면, 해당 원소를 바꿔주는 최적의 경우는
	배열의 모든 원소 중 제일 작은 값 2개를 골라 바꿔주는 경우이므로, 
	배열을 오름차순으로 정렬하여 A[1] + A[2]가 d이하이면 YES이다.
*/

#include<bits/stdc++.h>
using namespace std;

int A[101];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, d; cin >> n >> d;
		int mx = 0;
		for (int i = 1; i <= n; i++) cin >> A[i];
		sort(A + 1, A + 1 + n);
		if (A[n] <= d || A[1] + A[2] <= d) cout << "YES\n";
		else cout << "NO\n";
	}
}