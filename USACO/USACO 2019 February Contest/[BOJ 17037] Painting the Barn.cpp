/*
	[BOJ 17037] Painting the Barn (Silver)
	Algorithm : Prefix sum
*/
#include<bits/stdc++.h>
using namespace std;

int A[1010][1010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	vector<tuple<int, int, int>> v;
	for (int i = 1; i <= n; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a++; b++; c++; d++;
		A[a][b]++;
		A[c][d]++;
		A[a][d]--;
		A[c][b]--;
	}
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
		}
	}
	int ans = 0;
	for (int i = 1; i <= 1001; i++) {
		for (int j = 1; j <= 1001; j++) {
			if (A[i][j] == k) ans++;
		}
	}
	cout << ans;
}