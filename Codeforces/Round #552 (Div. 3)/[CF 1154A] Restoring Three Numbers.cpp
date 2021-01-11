/* [CF 1154A] Restoring Three Numbers
	Algorithm : Math

	입력으로 a+b, a+c, b+c, a+b+c가 랜덤 순서로 들어온다.
	이를 다 더하면 3(a+b+c) 이므로, a+b+c의 값을 구해줄 수 있다.
	따라서 구한 a+b+c의 값과 동일한 입력을 찾은 뒤, 해당 입력에서 나머지 세 입력을 빼주면 각각 a,b,c가 나온다.
*/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll a, b, c, d; cin >> a >> b >> c >> d;
	ll total = a + b + c + d;
	total /= 3;
	if (a == total) {
		cout << a - b << ' ' << a - c << ' ' << a - d;
	}
	else if (b == total) {
		cout << b - a << ' ' << b - c << ' ' << b - d;
	}
	else if (c == total) {
		cout << c - a << ' ' << c - b << ' ' << c - d;
	}
	else cout << d - a << ' ' << d - b << ' ' << d - c;

}