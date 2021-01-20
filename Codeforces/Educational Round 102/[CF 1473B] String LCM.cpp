/* [CF 1473B] String LCM
	Algorithm : Math / String

	���, ��� ���踦 ���ڿ��� �����ϴ� ����̴�.
	� ���ڿ� a�� b�� ����������ٴ� ���� b�� a�� ���ӵ� �κй��ڿ��� ����̴�.
	lcm(s, t)�� ���ϱ� ���ؼ��� lcm(|s|, |t|)�� ���ؼ� s�� lcm(|s|, |t|) / |s| ��ŭ, t�� lcm(|s|, |t|) / |t| ��ŭ ���� �̾�ٿ��� �� 
	�� ���ڿ��� �������� Ȯ�����ָ� �ȴ�.
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		string a, b; cin >> a >> b;
		string s1, s2;
		for (int i = 1; i <= lcm(sz(a), sz(b)) / sz(a); i++) s1 += a;
		for (int i = 1; i <= lcm(sz(a), sz(b)) / sz(b); i++) s2 += b;
		if (s1 == s2) cout << s1 << '\n';
		else cout << -1 << '\n';
	}
}