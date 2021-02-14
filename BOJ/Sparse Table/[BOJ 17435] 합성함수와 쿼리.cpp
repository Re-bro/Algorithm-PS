/* [BOJ 17435] 합성함수와 쿼리
	Algorithm : Sparse Table
*/
#include<bits/stdc++.h>
using namespace std;

int f[200001][20];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int m; cin >> m;
	for (int i = 1; i <= m; i++) cin >> f[i][0];
	for (int k = 1; k < 20; k++) {
		for (int i = 1; i <= m; i++) {
			f[i][k] = f[f[i][k - 1]][k - 1];
		}
	}
	int Q; cin >> Q;
	while (Q--) {
		int n, x; cin >> n >> x;
		for (int i = 0; i < 20; i++) {
			if (n & (1 << i)) x = f[x][i];
		}
		cout << x << '\n';
	}
}