/* [BOJ 9663] N-Queen
	Algorithm : Backtracking

	�� �ະ�� ���� ĭ�� ��ġ�� ����, �� �밢���� ���� �ִ��� üũ�Ѵ�.
*/
#include<bits/stdc++.h>
using namespace std;
int n;
bool chk[16];
bool dia[40], dia2[40];
int ans;
void sol(int row) {
	if (row == n + 1) {
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!chk[i] && !dia[15 + row-i] && !dia2[row + i]) {
			chk[i] = true;
			dia[15 + row - i] = true;
			dia2[row + i] = true;
			sol(row + 1);
			chk[i] = false;
			dia[15 + row - i] = false;
			dia2[row + i] = false;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n;
	sol(1);
	cout << ans;
}