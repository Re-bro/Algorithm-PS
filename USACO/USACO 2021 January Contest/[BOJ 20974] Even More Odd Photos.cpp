/*
	[BOJ 20974] Even More Odd Photos
	Algorithm : Greedy / Math
*/
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int odd = 0, even = 0;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (a % 2) odd++;
		else even++;
	}
	int ans = 0;
	for (int i = 0; i <= odd; i+=2) {
		int x = odd - i;
		int y = even + i / 2;
		if (y >= x + 1) {
			ans = max(ans, 2*x + 1);
		}
		else if (y >= x) ans = max(ans, 2 * x);
	}
	cout << ans;
}