/* 
	[BOJ 11868] ¥‘ ∞‘¿” 2
	Algorithm : Game Theory
*/
#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int k = 0;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		k ^= a;
	}
	if (k) cout << "koosaga";
	else cout << "cubelover";
}