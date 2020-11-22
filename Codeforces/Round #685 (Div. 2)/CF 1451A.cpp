/* Round #685 (Div. 2) A
	Algorithm : Greedy / Math

	n�� n�� �ƴ� ����� �����ų�, 1�� ���� 1�� ����� �����̴�.
	n�� ¦���� ���� n�� n/2�� ������ 2�� ���Եȴ�. 
	n�� Ȧ���� ���� 1�� ���� ¦���� ���� ���� (n-1)/2�� ������ �ȴ�.

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
		if (n <= 3) cout << n - 1 << '\n';
		else if (n % 2 == 0) cout << 2 << '\n';
		else cout << 3 << '\n';
	}
}
