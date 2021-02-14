/* [BOJ 4354] 문자열 제곱
	Algorithm : KMP

	s의 접미사이면서 접두사인 문자열 중 가장 긴 문자열의 길이를 k라고 하면, 
	k가 |s|/2 이상일 때 [0, |s| - k - 1] 만큼의 문자열이 계속해서 s에서 반복적으로 나타난다. 
	따라서 |s|-k-1이 |s|를 나누었을 때 나누어떨어진다면, a^n의 형태로 나타낼 수 있고, 
	그렇지 않으면 반복적으로 나타나는 문자열이 없다. 
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	while (1) {
		string s; cin >> s;
		if (s == ".") break;
		vector<int> fail(sz(s));
		for (int i = 1, j = 0; i < sz(s); i++) {
			while (j > 0 && s[i] != s[j]) j = fail[j - 1];
			if (s[i] == s[j]) fail[i] = ++j;
		}
		int k = sz(s) - fail[sz(s) - 1];
		if (sz(s) % k) cout << 1 << '\n';
		else cout << sz(s) / k << '\n';
	}
}