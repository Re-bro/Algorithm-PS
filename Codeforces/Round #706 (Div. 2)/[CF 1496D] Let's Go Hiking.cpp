/*
	[CF 1496D] Let's Go Hiking
	Algorithm : Game
*/
#include<bits/stdc++.h>
using namespace std;
int p[100001];
int al[100001];
int bl[100001];
int ar[100001];
int br[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 2; i <= n; i++) {
		if (p[i] > p[i - 1]) al[i] = max(al[i], al[i - 1] + 1);
		if (p[i] < p[i - 1]) bl[i] = max(bl[i], bl[i - 1] + 1);
	}
	for (int i = n - 1; i >= 1; i--) {
		if (p[i] > p[i + 1]) ar[i] = max(ar[i], ar[i + 1] + 1);
		if (p[i] < p[i + 1]) br[i] = max(br[i], br[i + 1] + 1);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) bl[i] = max(bl[i - 1], bl[i]);
	for (int i = n - 1; i >= 1; i--) br[i] = max(br[i], br[i + 1]);

	for (int i = 2; i < n; i++) {
		if (al[i] % 2 == 0 && al[i] == ar[i]) {
			if (min(al[i], ar[i]) > max(bl[i], br[i]) && (ar[i] >= br[1] && al[i] >= bl[n])) cnt++;
		}
	}
	cout << cnt;

}