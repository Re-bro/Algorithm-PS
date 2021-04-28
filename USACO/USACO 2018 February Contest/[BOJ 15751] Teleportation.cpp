/*
	[BOJ 15751] Teleportation
	Algorithm : Implementation
*/
#include<bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int a, b, x, y; cin >> a >> b >> x >> y;
	cout << min({ abs(a - b), abs(a - x) + abs(b - y), abs(a - y) + abs(b - x) });
}