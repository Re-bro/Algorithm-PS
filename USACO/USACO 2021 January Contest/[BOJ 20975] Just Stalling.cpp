/*
	[BOJ 20975] Just Stalling
	Algorithm : Greedy / Sorting
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int a[30], b[30];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	sort(b + 1, b + 1 + n);
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (a[j] <= b[i]) cnt++;
		}
		ans *= (cnt - i + 1);
	}
	cout << ans;
}