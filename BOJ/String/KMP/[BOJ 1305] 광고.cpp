/* [BOJ 1305] 광고
	Algorithm : KMP

	접두사이면서 접미사인 가장 긴 부분 문자열을 구하면, 
	전체 문자열 길이에서 해당 부분 문자열의 길이를 뺀 값이 답이다.
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int l; cin >> l;
	string s; cin >> s;
	vector<int> fail(sz(s));
	for (int i = 1, j = 0; i < sz(s); i++) {
		while (j > 0 && s[i] != s[j]) j = fail[j - 1];
		if (s[i] == s[j]) fail[i] = ++j;
	}
	cout << l - fail[l - 1];
}