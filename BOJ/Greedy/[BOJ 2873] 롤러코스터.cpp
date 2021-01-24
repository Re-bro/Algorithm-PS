/* [BOJ 2873] 롤러코스터
	Algorithm : Constructive / Greedy

	풀이 : https://www.slideshare.net/Baekjoon/baekjoon-online-judge-2873
*/

#include<bits/stdc++.h>
using namespace std;

int a[1001][1001];
int r, c;
void row(char a) {
	for (int i = 1; i < c; i++) cout << a;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> r >> c;
	for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) cin >> a[i][j];
	if (r % 2) {
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j < c; j++) {
				cout << (i % 2 ? 'R' : 'L');
			}
			if (i < r) cout << 'D';
		}
	}
	else if (c % 2) {
		for (int i = 1; i <= c; i++) {
			for (int j = 1; j < r; j++) {
				cout << (i % 2 ? 'D' : 'U');
			}
			if (i < c) cout << 'R';
		}
	}
	else {
		int mi = 10000;
		int x, y;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if ((i+j) % 2 && mi > a[i][j]) {
					x = i;
					y = j;
					mi = a[i][j];
				}
			}
		}
		for (int i = 1; i < x - 1; i += 2) {
			row('R'); cout << 'D';
			row('L'); cout << 'D';
		}
		for (int i = 1; i < y - 1; i += 2) {
			cout << "DRUR";
		}
		if (x % 2 == 0) cout << "RD";
		else cout << "DR";
		for (int i = y + 1; i < c; i += 2) {
			cout << "RURD";
		}
		for (int i = x + 1; i < r; i += 2) {
			cout << "D"; row('L');
			cout << 'D'; row('R');
		}
	}
}
