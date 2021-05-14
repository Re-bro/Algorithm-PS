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

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n, k; cin >> n >> k;
	if (n == k) cout << "Impossible";
	else {
		cout << n - k << ' ';
		for (int i = 1; i < n - k; i++) cout << i << ' ';
		for (int i = n - k + 1; i <= n; i++) cout << i << ' ';
	}
}