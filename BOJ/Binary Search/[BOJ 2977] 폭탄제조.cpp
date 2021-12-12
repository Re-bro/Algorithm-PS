#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[101][7];
bool sol(int k) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int need = a[i][1] * k - a[i][2];
		if (need <= 0) continue;
		if ((double) a[i][3] / a[i][4] >= (double)a[i][5] / a[i][6]) {
			int cost = (need + a[i][3] - 1) / a[i][3] * a[i][4];
			for (int j = (need + a[i][3] - 1) / a[i][3] - 1; j >= 0; j--) {
				int cost2 = j * a[i][4] + (max(0, (need - j * a[i][3])) + a[i][5] - 1) / a[i][5] * a[i][6];

				if (cost2 <= cost) cost = cost2;
			}
			sum += cost;
		}
		else {
			int cost = (need + a[i][5] - 1) / a[i][5] * a[i][6];
			for (int j = (need + a[i][5] -1) / a[i][5] - 1; j >= 0; j--) {
				int cost2 = j * a[i][6] + (max(0, (need - j * a[i][5])) + a[i][3] - 1) / a[i][3] * a[i][4];

				if (cost2 <= cost) cost = cost2;
			}
			sum += cost;
		}
		if (sum > m) return false;
	}
	if (sum <= m) return true;
	else return false;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) cin >> a[i][j];
	}
	int ans = 0;
	int s = 0; 
	int e = 110000;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (sol(mid)) {
			ans = max(ans, mid);
			s = mid + 1;
		}
		else e = mid - 1;
	}
	cout << ans;
}