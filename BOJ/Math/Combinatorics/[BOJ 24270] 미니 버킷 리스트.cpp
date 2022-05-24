#include<bits/stdc++.h>

using namespace std;
const int MOD = (int)1e9 + 7;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int s; cin >> s;
		sum += s;
	}
	long long ans = 1;
	for (int i = k-sum + 1; i <= n + k - sum; i++) {
		ans = (ans * i) % MOD;
	}
	cout << ans;
}