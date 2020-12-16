/* [CF 1462B] Last Year's Substring
	Algorithm : Implementation

	�ϳ� ������ ������ �����ؼ� "2020"�� ���� �� �ִ����� ���� �����̴�. 
	n�� �ִ� 200�̹Ƿ� 4���� ����� �ڸ��� ��� ��츦 ���غ��� �ȴ�.
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		string s; cin >> s;
		bool chk = false;
		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			int j = sz(s) - (4 - i) - 1;
			string tmp = "";
			for (int k = 0; k < sz(s); k++) {
				if (k >= i && k <= j) continue;
				tmp += s[k];
			}
			if (tmp == "2020") chk = true;

		}
		if (chk) cout << "YES\n";
		else cout << "NO\n";
	}
}