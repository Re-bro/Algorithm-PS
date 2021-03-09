/*
	[CF 1493A] Anti-knapsack
	Algorithm : Greedy / Math
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		vector<int> ans;
		for (int i = n; i > k; i--) ans.push_back(i);
		for (int i = k - 1; i >= (k + 1) / 2; i--) {
			ans.push_back(i);
		}
		cout << sz(ans) << '\n';
		for (int i : ans) cout << i << ' ';
		cout << '\n';
	}
}