/*
	[BOJ 14530] The Lost Cow
	Algorithm : Implementation
*/
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int x, y; cin >> x >> y;
	int X = x;
	int cnt = 0;
	for (int i = 1; ; i++) {
		for (int j = 1; j <= (1 << (i - 1)); j++) {
			if (i % 2) x++;
			else x--;
			cnt++;
			if (x == y) return cout << cnt, 0;
		}
		x = X;
		cnt += (1 << (i - 1));
	}
}