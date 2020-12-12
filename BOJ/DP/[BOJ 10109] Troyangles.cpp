/* [BOJ 10109] Troyangles
	Algorithm : DP

	(i, j)를 가장 윗 사각형으로 하면서 블록의 사이즈가 더 커지기 위해선, 
	(i+1, j-1), (i+1, j), (i+1, j+1)을 가장 윗 사각형으로 하는 동일한 크기의 블록이 존재해야 한다.
	따라서 아래의 세 지점에서 공통으로 가질 수 있는 최대의 크기를 구해서 
	A[i][j]에 더해주면 (i,j)에서 만들 수 있는 블록의 가짓수가 나온다.
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