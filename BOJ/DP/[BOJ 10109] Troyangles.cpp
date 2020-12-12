/* [BOJ 10109] Troyangles
	Algorithm : DP

	(i, j)�� ���� �� �簢������ �ϸ鼭 ����� ����� �� Ŀ���� ���ؼ�, 
	(i+1, j-1), (i+1, j), (i+1, j+1)�� ���� �� �簢������ �ϴ� ������ ũ���� ����� �����ؾ� �Ѵ�.
	���� �Ʒ��� �� �������� �������� ���� �� �ִ� �ִ��� ũ�⸦ ���ؼ� 
	A[i][j]�� �����ָ� (i,j)���� ���� �� �ִ� ����� �������� ���´�.
*/

#include<bits/stdc++.h>
using namespace std;
int A[2002][2002];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int ans = 0;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		for (int j = 0; j < n; j++) if (v[i][j] == '#') A[i + 1][j + 1] = 1;
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= n; j++) {
			if(A[i][j] == 1) A[i][j] += min(A[i + 1][j - 1], min(A[i + 1][j], A[i + 1][j + 1]));
			ans += A[i][j];
		}
	}
	cout << ans;
}