/* [BOJ 14601] 샤워실 바닥 깔기 (Large)
	Algorithm : Divide and Conquer / Recursion
	
	알맞게 타일을 배치하는 방법은 항상 존재한다. 
*/
#include<bits/stdc++.h>

using namespace std;
int k, X, Y;
int ans[150][150];
int num;
bool in(int x, int y, int sz) {
	for (int i = x; i < x + sz; i++) {
		for (int j = y; j < y + sz; j++) {
			if (ans[i][j] != 0) return 0;
		}
	}
	return 1;
}
void sol(int x, int y, int sz) {
	int s = sz / 2;
	num++;
	if (in(x, y, s)) ans[x + s - 1][y + s - 1] = num;
	if (in(x + s, y, s)) ans[x + s][y + s - 1] = num;
	if (in(x, y + s, s)) ans[x + s - 1][y + s] = num;
	if (in(x + s, y + s, s)) ans[x + s][y + s] = num;
	if (sz == 2) return;
	sol(x, y, s);
	sol(x + s, y, s);
	sol(x, y + s, s);
	sol(x + s, y + s, s);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> k >> X >> Y;
	ans[Y][X] = -1;
	sol(1, 1, 1 << k);
	for (int i =(1<<k); i >=1 ; i--) {
		for (int j = 1; j <= (1 << k); j++) cout << ans[i][j] << ' ';
		cout << '\n';
	}
}