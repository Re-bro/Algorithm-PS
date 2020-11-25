/* Round #686 (Div. 3) C
	Algorithm : Implementation

	1���� n������ ���� �߿���  �� ���ڸ� ������ ������ ���ڵ��� ������ ����
	���� ���� ���� ������ �ȴ�. 
	���� �տ� �ִ� ���� ���� �ڿ� �ִ� ��츦 �� �������.
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

int A[200001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<vector<int>> v(n + 1, vector<int>());
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			v[A[i]].push_back(i);
		}
		int ans = MAX;
		for (int i = 1; i <= n; i++) {
			if (sz(v[i]) == 0) continue;
			int cnt = 0;
			for (int j = 0; j < sz(v[i]); j++) {
				if (j == 0) {
					if (v[i][j] > 1) cnt++;
				}
				else {
					if (v[i][j] > v[i][j - 1] + 1) cnt++;
				}
				if (j == sz(v[i]) - 1 && v[i][j] < n) cnt++;
			}
			ans = min(ans, cnt);
		}
		cout << ans << '\n';
	}
}