/* [BOJ 20208] 진우의 민트초코우유
	Algorithm : Brute-Force

	주어지는 우유의 개수가 최대 10개이므로, 각 우유가 있는 지점을 방문하는
	순서를 순열로 구하면 최대 10! 이다. 
	따라서 모든 순열을 다 체크하면서, 현재까지 먹었을 때 집으로 돌아갈 수 있는지를 확인한다.
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

int A[11][11];
int ans = 0;
int N, M, H;
int dist(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N >> M >> H;
	vector<pii> milk;
	pii S;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			if (A[i][j] == 1) {
				S.first = i;
				S.second = j;
			}
			else if (A[i][j] == 2) {
				milk.push_back({ i, j });
			}
		}
	}
	do {
		int now = M;
		for (int i = 0; i < sz(milk); i++) {
			if (i == 0) {
				if (dist(S, milk[i]) <= now) {
					now -= dist(S, { milk[i] });
					now += H;
					if (dist(S, milk[i]) <= now) ans = max(ans, i + 1);
				}
				else break;
			}
			else {
				if (dist(milk[i - 1], milk[i]) <= now) {
					now -= dist(milk[i - 1], { milk[i] });
					now += H;
					if (dist(S, milk[i]) <= now) ans = max(ans, i + 1);
				}
				else break;
			}
		}
	} while (next_permutation(all(milk)));
	cout << ans;
}
