#include<bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	double n; cin >> n;
	n *= 1.08;
	int ans = (int)n;
	if (ans == 206) cout << "so-so";
	else if (ans < 206) cout << "Yay!";
	else cout << ":(";
}