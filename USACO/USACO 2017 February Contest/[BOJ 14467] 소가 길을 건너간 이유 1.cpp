/*
	[BOJ 14467] 소가 길을 건너간 이유 1
	Algorithm : Implementation
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;

int a[11];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	int n; cin >> n;
	ini(a, -1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		if (a[x] == -1) a[x] = y;
		else if (a[x] != y) {
			ans++;
			a[x] = y;
		}
	}
	cout << ans;
}