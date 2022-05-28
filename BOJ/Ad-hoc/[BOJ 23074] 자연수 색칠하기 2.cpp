#include<bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	if (n <= 3) cout << 1 << '\n';
	else cout << n/2 << '\n';
	for (int i = 1; i <= n; i++) {
		if (i <= 3) cout << 1 << ' ';
		else {
			cout << i / 2 << ' ';
		}
	}
}