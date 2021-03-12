/*
	[BOJ 20972] Spaced Out
	Algorithm : Greedy / Ad-hoc

	행기준 또는 열기준 둘 중 하나는 반드시 1칸씩 건너뛰는 형태로 나와야함.
	(== 2x2 정사각형에 반드시 2칸이 칠해지는 경우)
*/
#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; i++) {
		int odd = 0, even = 0;
		for (int j = 1; j <= n; j++) {
			if (j % 2) odd += a[i][j];
			else even += a[i][j];
		}
		ans1 += (odd > even) ? odd : even;
		odd = even = 0;
		for (int j = 1; j <= n; j++) {
			if (j % 2) odd += a[j][i];
			else even += a[j][i];
		}
		ans2 += (odd > even) ? odd : even; 
	}
	cout << max(ans1, ans2);
}