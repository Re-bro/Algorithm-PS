#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;

int n, L[101], R[101], dp[101][101];
int grundy(int l, int r) {
	if (l >= r) return 0;
	int& ret = dp[l][r];
	if (ret != -1) return ret;
	vector<bool> chk(101);
	for (int i = 1; i <= n; i++) {
		if (L[i] >= l && R[i] <= r) chk[grundy(l, L[i]) ^ grundy(R[i], r)] = true;
	}
	for (int i = 0; ; i++) {
		if (!chk[i]) {
			ret = i;
			break;
		}
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> L[i] >> R[i];
		}
		ini(dp, -1);
		if (grundy(1, 100)) cout << "Alice\n";
		else cout << "Bob\n";
	}
}