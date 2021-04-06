/*
	[BOJ 17039] Sleepy Cow Herding (Bronze)
	Algorithm : Implementation
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	vector<int> v(3);
	cin >> v[0] >> v[1] >> v[2];
	sort(all(v));
	int mi, mx;
	if (v[1] == v[0] + 1 && v[2] == v[1] + 1) cout << 0 << '\n' << 0;
	else {
		if (v[1] - v[0] == 2 || v[2] - v[1] == 2) mi = 1;
		else mi = 2;
		mx = max(v[1] - v[0], v[2] - v[1]) - 1;
		cout << mi << '\n' << mx;
	}
}