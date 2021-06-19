#include<bits/stdc++.h>
using namespace std;

int a[202020];
int P[202020];
int find(int a) {
	return P[a] == a ? a : P[a] = find(P[a]);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= 200000; i++) P[i] = i;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n / 2; i++) {
		int k1 = find(a[i]);
		int k2 = find(a[n + 1 - i]);
		if (k1 != k2) {
			P[k1] = k2;
			ans++;
		}
	}
	cout << ans;
}