/* [BOJ 18322] Word Processor
	Algorithm : Greedy
	
	줄마다 넣어주는데, 이번 단어를 썼을 때 해당 줄의 문자가 K개 초과가 되면
	다음 줄에 출력해준다.
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, K; cin >> N >> K;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		if (cnt + sz(s) <= K) {
			cout << s<<' ';
			cnt += sz(s);
		}
		else {
			cout << '\n';
			cout << s<<' ';
			cnt = sz(s);
		}
	}
}