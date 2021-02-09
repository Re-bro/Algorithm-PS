/* [BOJ 2339] ���� �ڸ���
	Algorithm : Divide and Conquer
	
	���ǿ� �Ҽ����� �ϳ��� ���� ������ �ϳ� �ִ� ��쿡�� 1�� return���ش�. 
	���ǿ� ������ �ϳ��� ���� ���� �Ұ����� ����̹Ƿ� 0�� return���ش�. 
	���� ������ A�� B �� �������� �����ٸ�, A������ ����� �� * B������ ����� ���� 
	���� ����� ���� �����ش�. 
*/
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n;
int A[21][21];
pii in(int x1, int y1, int x2, int y2) {
	int a = 0, b = 0;
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (A[i][j] == 2) a++;
			else if (A[i][j] == 1) b++;
		}
	}
	return { a, b };
}
int sol(int x1, int y1, int x2, int y2, bool turn) {
	if (x1 > x2 || y1 > y2) return 0;
	auto[a, b] = in(x1, y1, x2, y2);
	if (a == 0) return 0;
	else if (a == 1 && b == 0) return 1;
	int res = 0;
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (A[i][j] == 1) {
				if (turn) {
					bool chk = true;
					for (int k = y1; k <= y2; k++) {
						if (A[i][k] == 2) chk = false;
					}
					if (chk) res += sol(x1, y1, i - 1, y2, !turn) * sol(i + 1, y1, x2, y2, !turn);
				}
				else {
					bool chk = true;
					for (int k = x1; k <= x2; k++) {
						if (A[k][j] == 2) chk = false;
					}
					if (chk) res += sol(x1, y1, x2, j - 1, !turn) * sol(x1, j + 1, x2, y2, !turn);
				}
			}
		}
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}
	int ans = sol(1, 1, n, n, true) + sol(1, 1, n, n, false);
	if (ans == 0) cout << -1;
	else cout << ans;
}