/* [BOJ 1018] 체스판 다시 칠하기
	Algorithm : Brute-force
	
	모든 8x8 격자판에 대해서 경우의 수를 다 확인해보면 된다.
*/
#include<bits/stdc++.h>
using namespace std;
int n, m; 
vector<string>  v(50);
int sol(int x, int y) {
	int r1 = 0, r2 = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if ((i + j) % 2) {
				if (v[i][j] == 'W') r1++;
				else r2++;
			}
			else {
				if (v[i][j] == 'B') r1++;
				else r2++;
			}
		}
	}
	return min(r1, r2);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	int ans = 1e6;
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			ans = min(ans, sol(i, j));
		}
	}
	cout << ans;
}