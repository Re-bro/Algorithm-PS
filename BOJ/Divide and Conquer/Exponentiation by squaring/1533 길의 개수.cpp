/* [BOJ 1533] 길의 개수
	Algorithm : exponentiation by squaring with matrix

	설명 : 	https://wogud6792.tistory.com/77
	
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
const int MOD = 1000003;
const int MAX = 2e9;
const double PI = acos(-1);

ll N, S, E, T;
using mat = vector<vector<ll>>;
mat A;
mat ans;
mat operator *(mat &a, mat&b) {
	mat res(5 * N + 1, vector<ll>(5 * N + 1));
	for (int i = 1; i <= 5 * N; i++) {
		for (int j = 1; j <= 5 * N; j++) {
			for (int k = 1; k <= 5 * N; k++) {
				res[i][j] += (a[i][k] * b[k][j]);
				res[i][j] %= MOD;
			}
		}
	}
	return res;
}
void mpow(void) {
	while (T) {
		if (T % 2) {
			ans = ans *A;
		}
		T /= 2;
		A = A*A;
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N >> S >> E >> T;
	A.assign(5 * N + 1, vector<ll>(5*N+1));
	ans.assign(5 * N + 1, vector<ll>(5 * N + 1));
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		for (int j = 0; j < sz(s); j++) {
			if (s[j]-'0' >= 1) {
				A[i * 5][(j + 1) * 5 - (s[j] - '0' - 1)] = 1;
			}
		}
		for (int j = 1; j <= 4; j++) {
			A[(i - 1) * 5 + j][(i - 1) * 5 + j + 1] = 1;
		}
	}
	for (int i = 1; i <= 5 * N; i++) ans[i][i] = 1;
	mpow();
	cout << ans[5 * S][5 * E];
	
}