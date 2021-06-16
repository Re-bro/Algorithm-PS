#include<bits/stdc++.h>
using namespace std;

int a[1010];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (a[i] != i) {
			return cout << "No", 0;
		}
	}
	cout << "Yes";
}