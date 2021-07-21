/*
	[BOJ 16570] 앞뒤가 맞는 수열
	Algorithm : KMP
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010101];

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	reverse(a , a + n);
	vector<int> fail(n);
	int mx = -1;
	int cnt = 0;
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && a[i] != a[j]) j = fail[j - 1];
		if (a[i] == a[j]) fail[i] = ++j;
		if (mx < fail[i]) {
			mx = fail[i];
			cnt = 1;
		}
		else if (mx == fail[i]) {
			cnt++;
		}
	}
	if (mx == 0) cout << -1;
	else cout << mx << ' ' << cnt;
}