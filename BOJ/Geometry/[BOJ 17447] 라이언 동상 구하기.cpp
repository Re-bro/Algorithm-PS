/* [BOJ 17447] 라이언 동상 구하기
	Algorithm : Geometry/ CCW

	각 변에서 정점을 각각 잡는 경우의 수는 N^4 이므로 불가능하다.
	마주보는 두 변에서 정점을 각각 하나씩 잡으면, 남은 두 변의 정점을 잡는건 독립이다.
	따라서 N^3으로 가능하다.
	그리고, 선분을 그리면, 각 정점의 포함여부는 CCW로 판단한다.
*/
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MAX = (int)2e9;

int n, m; 
int Lu[500][500], Ru[500][500], Ld[500][500], Rd[500][500], V[500][500];
int ccw(pii a, pii b, pii c) {
	ll t = (ll)a.fi * b.se + (ll)b.fi * c.se + (ll)c.fi * a.se;
	t -= ((ll)b.fi * a.se + (ll)c.fi * b.se + (ll)a.fi* c.se);
	if (t > 0) return 1;
	else if (t < 0) return -1;
	else return 0;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	vector<pii> p;
	int total = 0;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		p.push_back({ a,b });
		cin >> V[a][b];
		total += V[a][b];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			int a = 0, b = 0, c = 0, d = 0;
			for (auto [x, y]: p) {
				if (ccw({ 0, i }, { j, n }, { x, y }) > 0) a += V[x][y];
				if (ccw({ 0, i }, { j, 0 }, { x, y }) < 0) b += V[x][y];
				if (ccw({ n, i }, { j, n }, { x, y }) < 0) c += V[x][y];
				if (ccw({ n, i }, { j, 0 }, { x, y }) > 0) d += V[x][y];
			}
			Lu[i][j] = a;
			Ld[i][j] = b;
			Ru[i][j] = c;
			Rd[i][j] = d;
		}
	}
	int mn = MAX;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			int m1 = MAX, m2 = MAX;
			for (int k = 1; k < n; k++) {
				m1 = min(Lu[i][k] + Ru[j][k], m1);
				m2 = min(Ld[i][k] + Rd[j][k], m2);
			}
			mn = min(mn, m1 + m2);
		}
	}
	cout << total - mn;
}