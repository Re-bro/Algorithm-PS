/*
	[BOJ 15753] Taming the Herd
	Algorithm : Implementation
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
#define fi first
#define se second

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);

int a[110];
int occur[110];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (a[1] > 0) return cout << -1, 0;
	a[1] = 0;
	for (int i = n; i >= 1; i--) {
		if (a[i] >= 0) {
			if (i - a[i] < 1) return cout << -1, 0;
			for (int j = i; j > i - a[i]; j--) {
				if (occur[j] == 1) return cout << -1, 0;
				occur[j] = -1;
			}
			occur[i - a[i]] = 1;
		}
	}
	int mi = 0, mx = 0;
	for (int i = 1; i <= n; i++) {
		if (occur[i] == 1) {
			mi++;
			mx++;
		}
		else if (occur[i] == 0) mx++;
	}
	cout << mi << ' ' << mx;
}