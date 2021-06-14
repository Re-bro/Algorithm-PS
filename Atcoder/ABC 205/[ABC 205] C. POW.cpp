#include<bits/stdc++.h>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int a, b, c; cin >> a >> b >> c;
	if (c % 2 == 0 || (a >= 0 && b >= 0)) {
		if (abs(a) > abs(b)) cout << '>';
		else if (abs(a) < abs(b)) cout << '<';
		else cout << '=';
	}
	else {
		if (a < 0 && b >= 0) cout << '<';
		else if (a >= 0 && b < 0) cout << '>';
		else {
			if (abs(a) > abs(b)) cout << '<';
			else if (abs(a) < abs(b))cout << '>';
			else cout << '=';
		}
	}

}