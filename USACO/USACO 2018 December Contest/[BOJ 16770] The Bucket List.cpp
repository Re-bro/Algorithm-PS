/*
	[BOJ 16770] The Bucket List
	Algorithm : Brute-force
*/
#include<bits/stdc++.h>
using namespace std;

int a[1010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int s, t, b; cin >> s >> t >> b;
		for (int j = s; j <= t; j++) {
			a[j] += b;
			ans = max(ans, a[j]);
		}
	}
	cout << ans;
}