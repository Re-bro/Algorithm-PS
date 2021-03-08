/*
	[CF 1159A] A pile of stones
	Algorithm : math
*/
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	string s; cin >> s;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '-') {
			cnt = max(cnt - 1, 0);
		}
		else cnt++;
	}
	cout << cnt;
}