/*
	[BOJ 16563] 어려운 소인수분해
	Algorithm : Number Theory / Prime number
*/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int P[5000001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	for (int i = 1; i <= 5000000; i++) P[i] = i;
	for (int i = 2; i <= 5000000; i++) {
		if (P[i] == i) {
			for (int j = i; i <= 10000 && j*i <= 5000000; j++) {
				if (P[i*j] == i * j) P[i*j] = i;
			}
		}
	}
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		while (k > 1) {
			cout << P[k] << ' ';
			k /= P[k];
		}
		cout << '\n';
	}
}