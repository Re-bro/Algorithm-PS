/* [BOJ 6568] 귀도 반 로썸은 크리스마스날 심심하다고 파이썬을 만들었다
	Algorithm : Implementation

*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
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
	string s; 
	while (cin>>s) {
		vector<string> v;
		v.push_back(s);
		for (int i = 1; i <= 31; i++) {
			cin >> s;
			v.push_back(s);
		}
		vector<int> mem(32);
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < 8; j++) {
				mem[i] += (v[i][j] - '0') * (1 << (7 - j));
			}
		}
		int pc = 0;
		int val = 0;
		while (1) {
			int o = 0, x = 0;
			o = mem[pc] / (1 << 5);
			x = mem[pc] % (1 << 5);
			pc++;
			if (pc == 32) pc = 0;
			if (o == 0) mem[x] = val;
			else if (o == 1) val = mem[x];
			else if (o == 2) {
				if (val == 0) pc = x;
			}
			else if (o == 3) continue;
			else if (o == 4) {
				val--;
				if (val < 0) val += (1 << 8);
			}
			else if (o == 5) {
				val++;
				if (val == (1 << 8)) val = 0;
			}
			else if (o == 6) pc = x;
			else {
				for (int i = 0; i < 8; i++) {
					if (val & (1 << (7 - i))) cout << 1;
					else cout << 0;
				}
				cout << '\n';
				break;
			}
		}
	}
}