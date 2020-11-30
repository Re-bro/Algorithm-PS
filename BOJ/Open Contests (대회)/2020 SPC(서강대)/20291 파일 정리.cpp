/* [BOJ 20291] 파일 정리 
	Algorithm : string, Implementation

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
	int N; cin >> N;
	vector<string> v;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		string tmp = "";
		for (int j = sz(s) - 1; j >= 0; j--) {
			if (s[j] == '.') break;
			tmp = s[j] + tmp;
		}
		v.push_back(tmp);
	}
	sort(all(v));
	int cnt = 1;
	for (int i = 1; i < sz(v); i++) {
		if (v[i] != v[i - 1]) {
			cout << v[i - 1] << ' ' << cnt << '\n';
			cnt = 1;
		}
		else cnt++;
	}
	cout << v[sz(v) - 1] << ' ' << cnt;
}