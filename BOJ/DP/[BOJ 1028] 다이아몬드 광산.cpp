/*
	[BOJ 1028] 다이아몬드 광산
	Algorithm : DP
*/
#include<bits/stdc++.h>
using namespace std;
int a[800][800];
int ur[800][800], ul[800][800], dr[800][800], dl[800][800];
int main(void) {
	int r, c; cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		string s; cin >> s;
		for (int j = 1; j <= c; j++) {
			a[i][j] = s[j - 1] - '0';
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (a[i][j] == 1) {
				ur[i][j] = ur[i - 1][j + 1] + 1;
				ul[i][j] = ul[i - 1][j - 1] + 1;
			}
		}
	}
	for (int i = r; i >= 1; i--) {
		for (int j = 1; j <= c; j++) {
			if (a[i][j] == 1) {
				dr[i][j] = dr[i + 1][j + 1] + 1;
				dl[i][j] = dl[i + 1][j - 1] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			for (int k = min(dl[i][j], dr[i][j]); k >= ans + 1; k--) {
				if (ul[i + 2 * (k - 1)][j] >= k && ur[i + 2 * (k - 1)][j] >= k) {
					ans = max(ans, k);
					break;
				}
			}
		}
	}
	cout << ans;
}