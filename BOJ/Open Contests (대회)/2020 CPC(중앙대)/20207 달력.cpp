/* [BOJ 20207] 달력
	Algorithm : Implementation

	일정이 연속된다면 무조건 하나의 직사각형으로 만들어야 하고, 
	직사각형의 높이는 그 중 가장 일정이 많은 날로 정해지므로 
	일정들을 모두 저장한 뒤, 일정이 없는날이 되면 그 전까지 구해놨던 정보로
	답에 더해준다. 
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

int A[370];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		int s, e; cin >> s >> e;
		for (int j = s; j <= e; j++) A[j]++;
	}
	int now = 0;
	int cnt = 0;
	int ans = 0;
	for (int i = 1; i <= 365; i++) {
		if (A[i] > 0) {
			cnt++;
			now = max(now, A[i]);
		}
		else {
			ans += now*cnt;
			now = cnt = 0;
		}
	}
	ans += now*cnt;
	cout << ans;
}
