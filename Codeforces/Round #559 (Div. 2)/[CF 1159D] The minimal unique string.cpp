/*
	[CF 1159D] The minimal unique string
	Algorithm : constructive / string 
*/
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	if (n == k) {
		for (int i = 1; i <= n; i++) cout << 1;
	}
	else {
		for (int i = 1; i <= (n - k) / 2; i++) cout << 1;
		cout << 0;
		for (int i = 1; i <= (n - k) / 2; i++) cout << 1;
		int cnt = (n - k) / 2;
		n -= cnt * 2 + 1;
		for (int i = 1; i <= n; i++) {
			if (i % (cnt + 1) == 1) cout << 0;
			else cout << 1;
		}
	}

}