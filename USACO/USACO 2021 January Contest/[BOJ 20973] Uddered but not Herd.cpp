/*
	[BOJ 20973] Uddered but not Herd
	Algorithm : String
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string s1, s2; cin >> s1 >> s2;
	vector<int> a(1001);
	for (int i = 0; i < sz(s2); i++) {
		for (int j = 0; j < sz(s1); j++) {
			if (s2[i] == s1[j]) {
				a[i+1] = j;
			}
		}
	}
	a[0] = 10000;
	int cnt = 0;
	for (int i = 1; i <= sz(s2); i++) {
		if (a[i] <= a[i - 1]) cnt++;
	}
	cout << cnt;
}