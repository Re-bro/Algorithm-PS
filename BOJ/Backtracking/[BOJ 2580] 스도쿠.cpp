/* [BOJ 2580] ½ºµµÄí
	Algorithm : Backtracking
*/

#include<bits/stdc++.h>
using namespace std;
bool sq[3][3][10], row[10][10], col[10][10];
int A[10][10];
int ans[10][10];
void sol(int x, int y) {
	if (x == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) ans[i][j] = A[i][j];
		}
		return;
	}
	if (y == 9) return sol(x + 1, 0);
	bool chk = false;
	for (int i = y; i < 9; i++) {
		if (A[x][i] == 0) {
			chk = true;
			bool chk2 = false;
			for (int j = 1; j <= 9; j++) {
				if (!sq[x / 3][i / 3][j] && !row[x][j] && !col[i][j]) {
					sq[x / 3][i / 3][j] = row[x][j] = col[i][j] = true;
					A[x][i] = j;					
					chk2 = true;
					sol(x, i + 1);
					sq[x / 3][i / 3][j] = row[x][j] = col[i][j] = false;
					A[x][i] = 0;
				}
			}
			if (!chk2) return;
			break;
		}
	}
	if (!chk) sol(x + 1, 0);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> A[i][j];
			if (A[i][j] > 0) {
				sq[i / 3][j / 3][A[i][j]] = true;
				row[i][A[i][j]] = true;
				col[j][A[i][j]] = true;
			}
		}
	}
	sol(0, 0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) cout << ans[i][j] << ' ';
		cout << '\n';
	}
}