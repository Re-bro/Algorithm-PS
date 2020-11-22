/* Round #685 (Div. 2) D
	Algorithm : Game / Math

	Ashish가 먼저 시작하므로, Utkarsh는 Ashish의 move를 보고 선택할 수 있다.
	만약 x축 이동과 y축 이동 횟수가 같으면서 더 이동하지 못하는 지점이 있다면, 
	Utkarsh가 무조건 이길 수 있다. (항상 Ashish의 반대로 move) 
	그 지점이 하나도 없다면, Ashish가 항상 이긴다. 
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
