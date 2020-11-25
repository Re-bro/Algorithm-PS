/* Round 686 (Div. 3) B
Algorithm : Implementation

1개 있는 값 중 가장 낮은 값을 구하면 된다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);


int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> cnt(n + 1, 0);
		vector<int> A(n + 1);
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			cnt[a]++;
			A[i] = a;
		}
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			if (cnt[i] == 1) {
				ans = i;
				break;
			}
		}
		if (ans == -1) cout << -1 << '\n';
		else {
			for (int i = 1; i <= n; i++) {
				if (A[i] == ans) {
					cout << i << '\n';
					break;
				}
			}
		}

	}
}