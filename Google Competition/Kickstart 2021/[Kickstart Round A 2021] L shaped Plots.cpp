/*
	[Kickstart Round A 2021] L shaped Plots
	Algorithm : Implementation / Prefix sum
*/
#include<bits/stdc++.h>
using namespace std;

int a[1010][1010];
int D[1010][1010]; 
int U[1010][1010]; 
int L[1010][1010]; 
int R[1010][1010]; 
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int r, c; cin >> r >> c;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cin >> a[i][j];
				D[i][j] = U[i][j] = L[i][j] = R[i][j] = a[i][j];
			}
		}
		for (int j = 1; j <= c; j++) {
			for (int i = r - 1; i >= 1; i--) {
				if (a[i][j] == 1) D[i][j] += D[i + 1][j];
			}
			for (int i = 2; i <= r; i++) {
				if (a[i][j] == 1) U[i][j] += U[i - 1][j];
			}
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 2; j <= c; j++) {
				if (a[i][j] == 1) L[i][j] += L[i][j - 1];
			}
			for (int j = c - 1; j >= 1; j--) {
				if (a[i][j] == 1) R[i][j] += R[i][j + 1];
			}
		}
		int ans = 0;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				ans += max(min(L[i][j] / 2, U[i][j]) - 1, 0);
				ans += max(min(U[i][j] / 2, L[i][j]) - 1, 0);
				ans += max(min(L[i][j] / 2, D[i][j]) - 1, 0);
				ans += max(min(D[i][j] / 2, L[i][j]) - 1, 0);
				ans += max(min(R[i][j] / 2, U[i][j]) - 1, 0);
				ans += max(min(U[i][j] / 2, R[i][j]) - 1, 0);
				ans += max(min(R[i][j] / 2, D[i][j]) - 1, 0);
				ans += max(min(D[i][j] / 2, R[i][j]) - 1, 0);
			}
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}
}