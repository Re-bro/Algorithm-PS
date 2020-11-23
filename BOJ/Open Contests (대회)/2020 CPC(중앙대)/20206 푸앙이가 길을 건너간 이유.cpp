/* [BOJ 20206] 푸앙이가 길을 건너간 이유
	Algorithm : Math

	직선이 위험 지역을 지난다면, 위험지역의 꼭짓점 중 직선을 기준으로 서로 반대편에 위치한 꼭짓점이 존재한다.  
	직선을 기준으로 어느 방향에 위치하는지는 직선의 방정식에 점의 좌표를 대입한 값이
	음수인지 양수인지에 따라 다르다. 
	따라서 부호가 다른 두 꼭짓점이 있는 경우 (0은 제외) Poor, 아니면 Lucky이다. 
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
	ll A, B, C; cin >> A >> B >> C;
	ll x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
	vector<ll> v(5);
	v[1] = A*x1 + B*y1 + C;
	v[2] = A*x2 + B*y1 + C;
	v[3] = A*x1 + B*y2 + C;
	v[4] = A*x2 + B*y2 + C;
	int c1 = 0;
	int c2 = 0;
	for (int i = 1; i <= 4; i++) {
		if (v[i] < 0) c1++;
		else if (v[i] > 0) c2++;
	}
	if (c1 > 0 && c2 > 0) cout << "Poor";
	else cout << "Lucky";
}
