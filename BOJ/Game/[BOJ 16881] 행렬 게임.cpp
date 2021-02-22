/* 
	[BOJ 16881] 행렬 게임
	Algorithm : Game / Sprague grundy
*/
#include<bits/stdc++.h>

using namespace std;

int a[1001][1001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int g = 0;
		for (int j = m; j >= 1; j--) {
			if (g == 0) g = a[i][j];
			else {
				if (g >= a[i][j]) g = a[i][j] - 1;
				else g = a[i][j];
			}
		}
		ans ^= g;
	}
	if (ans) cout << "koosaga";
	else cout << "cubelover";

}