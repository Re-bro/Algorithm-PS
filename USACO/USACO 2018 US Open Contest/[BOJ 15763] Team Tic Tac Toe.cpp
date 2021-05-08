/*
	[BOJ 15763] Team Tic Tac Toe
	Algorithm : Implementation
*/
#include<bits/stdc++.h>
using namespace std;

int a[3][3], row[3][26], col[3][26], dia1[26], dia2[26];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	for (int i = 0; i < 3; i++) {
		string s; cin >> s;
		for (int j = 0; j < 3; j++) {
			a[i][j] = s[j] - 'A';
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			row[i][a[i][j]]++;
			col[j][a[i][j]]++;
		}
		dia1[a[i][i]]++;
		dia2[a[i][2 - i]]++;
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < 26; i++) {
		bool chk = false;
		for (int j = 0; j < 3; j++) {
			if (row[j][i] == 3 || col[j][i] == 3) chk = true;
		}
		if (dia1[i] == 3 || dia2[i] == 3) chk = true;
		if (chk) ans1++;

		for (int j = i + 1; j < 26; j++) {
			chk = false;
			for (int k = 0; k < 3; k++) {
				if ((row[k][i] > 0 && row[k][j] > 0 &&row[k][i] + row[k][j] == 3) || (col[k][i] > 0 && col[k][j] > 0 &&col[k][i] + col[k][j] == 3)) chk = true;
			}
			if ((dia1[i] > 0 && dia1[j] > 0 &&dia1[i] + dia1[j] == 3) || (dia2[i] > 0 && dia2[j] > 0 && dia2[i] + dia2[j] == 3)) chk = true;
			if (chk) ans2++;
		}
	}
	cout << ans1 << '\n' << ans2;
}