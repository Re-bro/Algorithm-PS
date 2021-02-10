/* [BOJ 16916] 부분 문자열
	Algorithm : KMP algorithm

	KMP 알고리즘 기본 문제
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string s, p; cin >> s >> p;
	vector<int> fail(sz(p));
	for (int i = 1, j = 0; i < sz(p); i++) {
		while (j > 0 && p[i] != p[j]) j = fail[j - 1];
		if (p[i] == p[j]) fail[i] = ++j;
	}
	for (int i = 0, j = 0; i < sz(s); i++) {
		while (j > 0 && s[i] != p[j]) j = fail[j - 1];
		if (s[i] == p[j]) {
			if (j == sz(p) - 1) return cout << 1, 0;
			else j++;
		}
	}
	cout << 0;
}