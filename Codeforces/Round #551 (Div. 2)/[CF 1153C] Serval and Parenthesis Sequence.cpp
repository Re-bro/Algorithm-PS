/* [CF 1153C] Serval and Parenthesis Sequence
	Algorithm : Greedy

	'(', ')', '?'로 이루어진 문자열이 주어지고, '?'자리에는 '('와 ')'가 올 수 있다.
	전체 문자열이 'correct parenthesis sequence' 가 되어야 하고, prefix들은 되면 안된다.
	따라서 먼저, 문자열의 길이가 홀수이면 correct할 수 없고, 주어지는 문자열에서 '('의 개수가 절반을 넘거나 ')'의 개수가 절반을 넘으면 '?'를 이용해도 correct할 수 없다.
	이 경우들을 모두 제거해주고, prefix들이 correct할 수 없도록 '?' 를 앞에서부터 최대한 '('로 바꿔준다.
	최종적으로 바꾼 후에 만들어진 문자열이 문제 조건을 만족하는지 다시 체크해준다.
*/

#include<bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	string s; cin >> s;
	if (n % 2) return cout << ":(", 0;
	int l = 0, r = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') l++;
		else if (s[i] == ')') r++;
	}
	if (l > n / 2 || r > n / 2) return cout << ":(", 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			if (l < n / 2) {
				s[i] = '(';
				l++;
			}
			else s[i] = ')';
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') cnt++;
		else {
			cnt--;
			if (i != n - 1 && cnt <= 0) return cout << ":(", 0;
		}
	}
	cout << s;
} 