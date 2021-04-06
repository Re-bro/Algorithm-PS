/*
	[BOJ 16771] Back and Forth
	Algorithm : Brute-force / Implementation
*/

#include<bits/stdc++.h>
using namespace std;

int a[11], b[11];
set<int> s;
bool chk1[11], chk2[11];
void sol(int cnt, int val) {
	if (cnt == 4) {
		s.insert(val);
		return;
	}
	if (cnt % 2 == 0) {
		for (int i = 1; i <= 10; i++) {
			if (!chk1[i]){
				chk1[i] = true;
				sol(cnt + 1, val - a[i]);
				chk1[i] = false;
			}
			if (chk2[i]) {
				chk2[i] = false;
				sol(cnt + 1, val - b[i]);
				chk2[i] = true;
			}
		}
	}
	else {
		for (int i = 1; i <= 10; i++) {
			if (!chk2[i]) {
				chk2[i] = true;
				sol(cnt + 1, val + b[i]);
				chk2[i] = false;
			}
			if (chk1[i]) {
				chk1[i] = false;
				sol(cnt + 1, val + a[i]);
				chk1[i] = true;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	for (int i = 1; i <= 10; i++) cin >> a[i];
	for (int i = 1; i <= 10; i++) cin >> b[i];
	sol(0, 0);
	cout << s.size();
}