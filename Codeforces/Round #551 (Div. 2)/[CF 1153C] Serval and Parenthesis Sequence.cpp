/* [CF 1153C] Serval and Parenthesis Sequence
	Algorithm : Greedy

	'(', ')', '?'�� �̷���� ���ڿ��� �־�����, '?'�ڸ����� '('�� ')'�� �� �� �ִ�.
	��ü ���ڿ��� 'correct parenthesis sequence' �� �Ǿ�� �ϰ�, prefix���� �Ǹ� �ȵȴ�.
	���� ����, ���ڿ��� ���̰� Ȧ���̸� correct�� �� ����, �־����� ���ڿ����� '('�� ������ ������ �Ѱų� ')'�� ������ ������ ������ '?'�� �̿��ص� correct�� �� ����.
	�� ������ ��� �������ְ�, prefix���� correct�� �� ������ '?' �� �տ������� �ִ��� '('�� �ٲ��ش�.
	���������� �ٲ� �Ŀ� ������� ���ڿ��� ���� ������ �����ϴ��� �ٽ� üũ���ش�.
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