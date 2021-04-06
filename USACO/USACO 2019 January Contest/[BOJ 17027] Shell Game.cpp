/*
	[BOJ 17027] Shell Game
	Algorithm : Implementation
*/

#include<bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<tuple<int, int, int>> v;
	for (int i = 1; i <= n; i++) {
		int a, b, g; cin >> a >> b >> g;
		v.push_back(make_tuple(a, b, g));
	}
	int ans = 0;
	for (int i = 1; i <= 3; i++) {
		int cnt = 0;
		vector<int> A(5);
		A[i] = 1;
		for (auto[a, b, g] : v) {
			swap(A[a], A[b]);
			if (A[g] == 1) cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}