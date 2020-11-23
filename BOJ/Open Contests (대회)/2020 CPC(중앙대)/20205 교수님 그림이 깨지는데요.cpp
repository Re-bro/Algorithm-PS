/* [BOJ 20205] 교수님 그림이 깨지는데요?
	Algorithm : implementation

	단순 구현 문제.
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
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N, K; cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> A[i][j];
	}
	for (int i = 0; i < N*K; i++) {
		for (int j = 0; j < N*K; j++) cout << A[i / K][j / K] << ' ';
		cout << '\n';
	}
}
