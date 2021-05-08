/*
	[BOJ 17028] Sleepy Cow Sorting
	Algorithm : Ad-hoc
*/
#include<bits/stdc++.h>
using namespace std;

int a[101];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = 10000;
	for (int i = n; i >=1; i--) {
		if (a[i] < a[i - 1]) return cout << i - 1, 0;
	}
}