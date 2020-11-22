/* Round #685 (Div. 2) D
	Algorithm : Game / Math

	Ashish�� ���� �����ϹǷ�, Utkarsh�� Ashish�� move�� ���� ������ �� �ִ�.
	���� x�� �̵��� y�� �̵� Ƚ���� �����鼭 �� �̵����� ���ϴ� ������ �ִٸ�, 
	Utkarsh�� ������ �̱� �� �ִ�. (�׻� Ashish�� �ݴ�� move) 
	�� ������ �ϳ��� ���ٸ�, Ashish�� �׻� �̱��. 
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
		ll d, k; cin >> d >> k;
		bool chk = false;
		for (ll x = (d / k)*k; x >= k; x -= k) {
			ll y = (ll)sqrt(d*d - x*x);
			y = (y / k)*k;
			if (x == y) chk = true;
		}
		if (chk) cout << "Utkarsh\n";
		else cout << "Ashish\n";
	}
}
