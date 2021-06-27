/*
	[BOJ 14465] 소가 길을 건너간 이유 5
	Algorithm : Prefix sum / Sliding window
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;

int a[101010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, k, b; cin >> n >> k >> b;
	for (int i = 1; i <= b; i++) {
		int x; cin >> x;
		a[x] = 1;
	}
	int ans = MAX;
	for (int i = 1; i <= n; i++) a[i] += a[i - 1];
	for (int i = k; i <= n; i++) {
		ans = min(ans, a[i] - a[i - k]);
	}
	cout << ans;
}