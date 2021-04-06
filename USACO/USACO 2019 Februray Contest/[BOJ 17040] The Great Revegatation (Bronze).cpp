/*
	[BOJ 17040] The Great Revegatation (Bronze)
	Algorithm : Brute-force / Implementation
*/
#include<bits/stdc++.h>
using namespace std;
bool chk[101][101];
int ans[101];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		chk[a][b] = chk[b][a] = true;
	}
	for (int i = 1; i <= n; i++) {
		vector<bool> tmp(n + 1);
		for (int j = 1; j <= n; j++) {
			if (chk[i][j]) tmp[ans[j]] = true;
		}
		for (int j = 1; j <= n; j++) {
			if (!tmp[j]) {
				ans[i] = j;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i];
}