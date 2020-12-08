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
		int n; cin >> n;
		vector<string> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		int x0 = 0, x1 = 0, x2 = 0;
		int o0 = 0, o1 = 0, o2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((i + j) % 3 == 0) {
					if (v[i][j] == 'X') x0++;
					else if (v[i][j] == 'O')o0++;
				}
				else if ((i + j) % 3 == 1) {
					if (v[i][j] == 'X') x1++;
					else if (v[i][j] == 'O') o1++;
				}
				else {
					if (v[i][j] == 'X') x2++;
					else if (v[i][j] == 'O') o2++;
				}
			}
		}
		vector<pii>vc;
		vc.push_back({ x0 + o1, 1 });
		vc.push_back({ x0 + o2, 2 });
		vc.push_back({ x1 + o0, 3 });
		vc.push_back({ x1 + o2, 4 });
		vc.push_back({ x2 + o0, 5 });
		vc.push_back({ x2 + o1, 6 });
		sort(all(vc));
		int k = vc[0].second;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (k == 1) {
					if ((i + j) % 3 == 0 && v[i][j] == 'X') v[i][j] = 'O';
					if ((i + j) % 3 == 1 && v[i][j] == 'O') v[i][j] = 'X';
				}
				else if (k == 2) {
					if ((i + j) % 3 == 0 && v[i][j] == 'X') v[i][j] = 'O';
					if ((i + j) % 3 == 2 && v[i][j] == 'O') v[i][j] = 'X';
				}
				else if (k == 3) {
					if ((i + j) % 3 == 1 && v[i][j] == 'X') v[i][j] = 'O';
					if ((i + j) % 3 == 0 && v[i][j] == 'O')v[i][j] = 'X';
				}
				else if (k == 4) {
					if ((i + j) % 3 == 1 && v[i][j] == 'X') v[i][j] = 'O';
					if ((i + j) % 3 == 2 && v[i][j] == 'O') v[i][j] = 'X';
				}
				else if (k == 5) {
					if ((i + j) % 3 == 2 && v[i][j] == 'X') v[i][j] = 'O';
					if ((i + j) % 3 == 0 && v[i][j] == 'O')v[i][j] = 'X';
				}
				else {
					if ((i + j) % 3 == 2 && v[i][j] == 'X') v[i][j] = 'O';
					if ((i + j) % 3 == 1 && v[i][j] == 'O')v[i][j] = 'X';
				}
			}
		}
		for (int i = 0; i < n; i++) cout << v[i] << '\n';
	}
}