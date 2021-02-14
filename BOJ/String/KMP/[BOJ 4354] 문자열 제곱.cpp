/* [BOJ 4354] ���ڿ� ����
	Algorithm : KMP

	s�� ���̻��̸鼭 ���λ��� ���ڿ� �� ���� �� ���ڿ��� ���̸� k��� �ϸ�, 
	k�� |s|/2 �̻��� �� [0, |s| - k - 1] ��ŭ�� ���ڿ��� ����ؼ� s���� �ݺ������� ��Ÿ����. 
	���� |s|-k-1�� |s|�� �������� �� ����������ٸ�, a^n�� ���·� ��Ÿ�� �� �ְ�, 
	�׷��� ������ �ݺ������� ��Ÿ���� ���ڿ��� ����. 
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