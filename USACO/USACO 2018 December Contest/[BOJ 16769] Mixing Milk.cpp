/*
	[BOJ 16769] Mixing Milk
	Algorithm : Implementation
*/
#include<bits/stdc++.h>
using namespace std;

int c[3], m[3];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 3; i++) {
		cin >> c[i] >> m[i];
	}
	for (int i = 1; i <= 100; i++) {
		int mi = min(c[i%3] - m[i%3], m[(i - 1)%3]);
		m[i % 3] += mi;
		m[(i - 1) % 3] -= mi;
	}
	for (int i = 0; i < 3; i++) cout << m[i] << '\n';
}