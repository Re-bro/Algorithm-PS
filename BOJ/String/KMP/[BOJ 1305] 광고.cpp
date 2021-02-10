/* [BOJ 1305] ����
	Algorithm : KMP

	���λ��̸鼭 ���̻��� ���� �� �κ� ���ڿ��� ���ϸ�, 
	��ü ���ڿ� ���̿��� �ش� �κ� ���ڿ��� ���̸� �� ���� ���̴�.
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