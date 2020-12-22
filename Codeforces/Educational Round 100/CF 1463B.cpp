/* [CF 1463B] Find The Array
	Algorithm : Constructive

	각 원소별로 자신을 넘지 않으면서 최대의 2의 제곱수를 할당해주면 된다.
	그러면 ai - bi를 하게 되면 ai의 MSB가 빠지게 되고, 이 값은 
	ai - bi보다 크기 때문에 조건3도 만족하게 된다. 
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll A[51];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		ll total = 0;
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			for (int j = 30; j >= 0; j--) {
				if ((1LL << j) & A[i]) {
					cout << (1 << j) << ' ';
					break;
				}
			}
		}
		cout << '\n';
	}
}