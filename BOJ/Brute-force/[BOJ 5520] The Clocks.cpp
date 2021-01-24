/* [BOJ 5520] The Clocks
	Algorithm : Brute-force
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

int a[9];
int mov[9];
int cnt[9];
int ans[9];
int mn = 100;
void sol(int idx) {
	if (idx == 9) {
		bool chk = true;
		for (int i = 0; i < 9; i++) {
			int tmp = 0;
			for (int j = 0; j < 9; j++) {
				if (mov[j] & (1 << i)) tmp += cnt[j];
			}
			if ((a[i] + tmp)% 4 != 0) chk = false;
		}
		if (chk) {
			int c = 0;
			for (int i = 0; i < 9; i++) {
				c += cnt[i];
			}
			if (c <mn || mn == 0) {
				for (int i = 0; i < 9; i++) ans[i] = cnt[i];
			}
		}
		return;
	}
	sol(idx + 1);
	cnt[idx] = 1;
	sol(idx + 1);
	cnt[idx] = 2;
	sol(idx + 1);
	cnt[idx] = 3;
	sol(idx + 1);
	cnt[idx] = 0;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 9; i++) cin >> a[i];
	vector<string> v = { "ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI" };
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < sz(v[i]); j++) {
			mov[i] |= (1<<(v[i][j] - 'A'));
		}
	}
	sol(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < ans[i]; j++) cout << i + 1 << ' ';
	}
}