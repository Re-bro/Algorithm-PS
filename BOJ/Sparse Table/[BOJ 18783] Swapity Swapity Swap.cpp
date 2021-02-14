/* 
	[BOJ 18783] Swapity Swapity Swap
	Algorithm : Sparse Table
*/
#include<bits/stdc++.h>
using namespace std;

int f[100001][35];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n+1), ans(n+1);
	for (int i = 1; i <= n; i++) {
		a[i] = ans[i] = i;
	}
	while (m--) {
		int l, r; cin >> l >> r;
		reverse(a.begin() + l, a.begin() + r + 1);
	}
	for (int k = 0; k < 35; k++) {
		for (int i = 1; i <= n; i++) {
			if (k == 0) f[i][0] = a[i];
			else f[i][k] = f[f[i][k - 1]][k - 1];
		}
	}
	int cnt = 0;
	while (k > 0) {
		if (k % 2) {
			for (int i = 1; i <= n; i++) {
				ans[i] = f[ans[i]][cnt];
			}
		}
		k /= 2;
		cnt++;
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}