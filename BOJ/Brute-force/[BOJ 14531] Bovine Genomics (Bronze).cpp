/*
	[BOJ 14531] Bovine Genomics (Bronze)
	Algorithm : Brute-force / Implementation
*/
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n, m; cin >> n >> m;
	vector<string> v1(n), v2(n);
	for (int i = 0; i < n; i++) cin >> v1[i];
	for (int i = 0; i < n; i++) cin >> v2[i];
	int ans = 0;
	for (int i = 0; i < m; i++) {
		set<char>s;
		for (int j = 0; j < n; j++) {
			s.insert(v1[j][i]);
		}
		bool chk = true;
		for (int j = 0; j < n; j++) {
			if (s.find(v2[j][i]) != s.end()) chk = false;
		}
		if (chk) ans++;
	}
	cout << ans;
}