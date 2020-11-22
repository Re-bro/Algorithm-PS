/* Round #685 (Div. 2) B
	Algorithm : implementation

	[l, r]구간과 동일하게 substring을 구할 수 있는지에 대한 문제이다.
	substring이 원래의 string에서 연속되면 안되고, 0과 1만 존재하므로
	s[l]과 같은 문자가 1 ~ l-1에 존재하는지, 
	s[r]과 같은 문자가 r+1 ~ n에 존재하는지만 체크해주면 충분하다. 
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
		int n, q; cin >> n >> q;
		string s; cin >> s;
		for (int i = 1; i <= q; i++) {
			int l, r; cin >> l >> r;
			l--;
			r--;
			bool check = false;
			for (int j = l - 1; j >= 0; j--) {
				if (s[j] == s[l]) check = true;
			}
			for (int j = r + 1; j < n; j++) {
				if (s[j] == s[r]) check = true;
			}
			if (check) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
