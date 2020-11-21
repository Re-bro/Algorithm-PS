/* CF Educational round 98 A
	Algorithm : Math

	�����ؼ� ���� 	�̵��� �� �� �����Ƿ�
	x�� y�� 2�̻� ���̳��ٸ� ���̿� ������ �ִ� ������ �ʿ��ϴ�. 
	ex) x = 2, y = 4 -> yxyxyoy (o : stay)
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
		int x, y; cin >> x >> y;
		cout << max(abs(x - y) - 1, 0) + x + y << '\n';
	}
}
