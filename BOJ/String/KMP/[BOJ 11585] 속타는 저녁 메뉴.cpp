/* [BOJ 11585] ��Ÿ�� ���� �޴�
	Algorithm : KMP

	�־����� ���ڿ� �ΰ��� �̾� �ٿ���, ���ϰ� ��ġ�ϴ� �κ��� ���� �ε�����
	n-1 �����̸� �ش� �κ� ���ڿ��� ��⸦ ���� �� �ִ� ������ ����̴�.
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