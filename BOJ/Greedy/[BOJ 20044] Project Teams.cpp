/* [BOJ 20044] Project Teams
	Algorithm : Greedy

	정렬하고 양 끝끼리 쌍을 지어준다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);

int w[10001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= 2 * n; i++) cin >> w[i];
	sort(w + 1, w + 1 + 2 * n);
	int ans = MAX;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, w[i] + w[2 * n + 1 - i]);
	}
	cout << ans;
}