/*
	[BOJ 19541] 역학 조사
	Algorithm : Implementation / Simutation
*/
#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> v[101010];
int ori[101010], tmp[101010], ans[101010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		while (k--) {
			int a; cin >> a;
			v[i].pb(a);
		}
	}
	for (int i = 1; i <= n; i++) cin >> ori[i], ans[i] = ori[i];
	for (int i = m - 1; i >= 0; i--) {
		int bit = 0;
		for (int j : v[i]) {
			if (ans[j]) bit |= 2;
			else bit |= 1;
		}
		if (bit == 3) {
			for (int j : v[i]) {
				ans[j] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) tmp[i] = ans[i];
	for (int i = 0; i < m; i++) {
		bool chk = false;
		for (int j : v[i]) {
			if (tmp[j] == 1) chk = true;
		}
		if (chk) {
			for (int j : v[i]) {
				tmp[j] = 1;
			}
		}
	}
	bool chk = true;
	for (int i = 1; i <= n; i++) {
		if (tmp[i] != ori[i]) chk = false;
	}
	if (chk) {
		cout << "YES\n";
		for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	}
	else cout << "NO";
}