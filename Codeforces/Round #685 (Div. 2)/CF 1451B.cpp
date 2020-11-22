/* Round #685 (Div. 2) B
	Algorithm : implementation

	[l, r]������ �����ϰ� substring�� ���� �� �ִ����� ���� �����̴�.
	substring�� ������ string���� ���ӵǸ� �ȵǰ�, 0�� 1�� �����ϹǷ�
	s[l]�� ���� ���ڰ� 1 ~ l-1�� �����ϴ���, 
	s[r]�� ���� ���ڰ� r+1 ~ n�� �����ϴ����� üũ���ָ� ����ϴ�. 
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
