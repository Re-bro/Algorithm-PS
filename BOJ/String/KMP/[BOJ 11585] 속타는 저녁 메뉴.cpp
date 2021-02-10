/* [BOJ 11585] 속타는 저녁 메뉴
	Algorithm : KMP

	주어지는 문자열 두개를 이어 붙여서, 패턴과 일치하는 부분의 시작 인덱스가
	n-1 이하이면 해당 부분 문자열은 고기를 먹을 수 있는 가능한 경우이다.
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	string s = "";
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		s += c;
	}
	string p = "";
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		p += c;
	}
	s += s;
	vector<int> fail(sz(p));
	for (int i = 1, j = 0; i < sz(p); i++) {
		while (j > 0 && p[i] != p[j]) j = fail[j - 1];
		if (p[i] == p[j]) fail[i] = ++j;
	}
	int cnt = 0;
	for (int i = 0, j=0; i < sz(s); i++) {
		while (j > 0 && s[i] != p[j]) j = fail[j - 1];
		if (s[i] == p[j]) {
			if (j == sz(p) - 1 && i - sz(p) + 1 < n) {
				cnt++;
				j = fail[j];
			}
			else j++;
		}
	}
	int g = gcd(cnt, n);
	cout << cnt / g << '/' << n / g;

}