/*
	[BOJ 15761] Lemonade Line
	Algorithm : Sorting / Greedy
*/
#include<bits/stdc++.h>
using namespace std;
int w[101010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	sort(w + 1, w + 1 + n, greater<int>());
	for (int i = 1; i <= n; i++) {
		if (w[i] < i - 1) return cout << i - 1, 0;
	}
	cout << n;
}