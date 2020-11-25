/* Round 686 (Div. 3) A
	Algorithm : Constructive

	p[i] = i가 되지 않도록 순열을 만드는 문제다.
	2 , 3, ... , n, 1 로 만들면 된다.
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
		for (int i = 2; i <= n; i++) cout << i << ' ';
		cout << 1 << '\n';
	}
}
