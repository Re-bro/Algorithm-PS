#include<bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; ; i++) {
		if (i * (i + 1) / 2 >= n) {
			cout << i;
			break;
		}
	}
}