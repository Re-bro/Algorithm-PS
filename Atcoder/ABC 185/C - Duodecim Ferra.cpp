#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);

ll combi[201][13];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	ll L;  cin >> L;
	combi[1][0] = combi[1][1] = 1;
	for (int i = 2; i <= L; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) combi[i][j] = 1;
			else combi[i][j] = combi[i - 1][j - 1] + combi[i - 1][j];
		}
	}
	cout << combi[L - 1][11];
}