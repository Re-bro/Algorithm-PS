/* [BOJ 20292] 컨설팅
	Algorithm : Implementation

	풀이 : https://wogud6792.tistory.com/78
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
	map<string, int> mp1, mp2, mp3, w;
	vector<vector<string>> ans;
	while (1) {
		string s; cin >> s;
		if (s == "EXIT") break;
		else if (s == "WRITE") {
			string a, tmp, b; cin >> a >> tmp >> b;
			if (mp1[b] > 0 || mp2[b]>0 || mp2[a] > 0 || mp3[b] > 0 || w[s + a + tmp + b] > 0 || w[s + b + tmp + a] > 0) {
				ans.push_back({ "WAIT" });
				ans.push_back({ s,a, tmp, b });
				mp1.clear(); mp2.clear(); mp3.clear(); w.clear();
				mp1[a] = 1; mp2[b] = 1;
				w[s + a + tmp + b] = 1;
			}
			else {
				ans.push_back({ s, a, tmp , b });
				mp1[a]++; mp2[b]++;
				w[s + a + tmp + b] = 1;
			}
		}
		else {
			string a; cin >> a;
			if (mp2[a] > 0) {
				ans.push_back({ "WAIT" });
				ans.push_back({ s, a });
				mp1.clear(); mp2.clear(); mp3.clear(); w.clear();
				mp3[a]++;
			}
			else {
				ans.push_back({ s, a });
				mp3[a]++;
			}
		}
	}
	for (int i = 0; i < sz(ans); i++) {
		for (string st : ans[i]) cout << st << ' ';
		cout << '\n';
	}
	cout << "EXIT";
}