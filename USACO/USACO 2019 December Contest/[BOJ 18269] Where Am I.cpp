/* [BOJ 18269] Where Am I?
	Algorithm : Brute-force
	
	K의 길이를 갖는 모든 부분문자열이 서로 다른 최소의 K를 찾는 문제이다.
	제한이 작으므로 직접 모든 부분문자열을 만들어서 체크해보면 된다.
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	string s; cin >> s;
	for (int i = 1; i <= N; i++) {
		set<string> S;
		bool chk = true;
		for (int j = 0; j + i <= sz(s); j++) {
			if (S.find(s.substr(j, i)) != S.end()) chk = false;
			S.insert(s.substr(j, i));
		}
		if (chk) {
			cout << i;
			break;
		}
	}
}