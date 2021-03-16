/*
	[BOJ 20651] Daisy Chains
	Algorithm : Brute-force
*/
#include<bits/stdc++.h>
using namespace std;

int p[101];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i]; p[i] += p[i - 1];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int k = i; k <= j; k++) {
				if (p[j] - p[i - 1] == (p[k] - p[k-1])* (j - i + 1)) {
					cnt++;
					break;
				}
			}
		}
	}
	cout << cnt;
}