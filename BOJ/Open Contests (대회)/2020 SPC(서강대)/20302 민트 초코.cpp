/* [BOJ 20302] 민트 초코
	Algorithm : Math, Number theory

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
int cnt[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	vector<int> v1, v2;
	int a; cin >> a;
	bool chk = false;
	v1.push_back(a);
	if (a == 0) chk = true;
	for (int i = 1; i < N; i++) {
		char c; cin >> c;
		cin >> a;
		if (a == 0) {
			chk = true;
		}
		a = abs(a);
		if (c == '/') v2.push_back(a);
		else v1.push_back(a);
	}
	if (chk) {
		cout << "mint chocolate";
		return 0;
	}
	for (int i = 0; i < sz(v1); i++) {
		int k = v1[i];
		for (int j = 2; j*j <= v1[i]; j++) {
			while (k>1) {
				if (k%j == 0) {
					cnt[j]++;
					k /= j;
				}
				else break;
			}
		}
		if (k > 1) cnt[k]++;
	}
	for (int i = 0; i < sz(v2); i++) {
		int k = v2[i];
		for (int j = 2; j*j <= v2[i]; j++) {
			while (k>1) {
				if (k%j == 0) {
					cnt[j]--;
					k /= j;
				}
				else break;
			}
		}
		if (k > 1) cnt[k]--;
	}
	bool check = true;
	for (int i = 1; i <= 100000; i++) if (cnt[i] < 0) check = false;
	if (check) cout << "mint chocolate";
	else cout << "toothpaste";
}