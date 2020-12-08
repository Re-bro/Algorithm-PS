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

int A[300001];
int ans[300001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> cnt(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			ans[i] = 0;
			cnt[A[i]]++;
		}
		bool chk = true;
		for (int i = 1; i <= n; i++) {
			if (cnt[i] != 1) chk = false;
		}
		if (chk) ans[1] = 1;
		if (cnt[1] >= 1) {
			ans[n] = 1;
			int l = 1;
			int r = n;
			for (int i = n; i > 1; i--) {
				ans[i] = 1;
				int next = n - i + 1;
				cnt[next]--;
				if (cnt[next] == 0 && cnt[next + 1] > 0) {
					if (A[l] == next) l++;
					else if (A[r] == next) r--;
					else break;
				}
				else break;
			}
		}
		for (int i = 1; i <= n; i++) cout << ans[i];
		cout << '\n';
	}
}