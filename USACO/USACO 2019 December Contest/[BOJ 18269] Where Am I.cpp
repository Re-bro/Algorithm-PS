/* [BOJ 18269] Where Am I?
	Algorithm : Brute-force
	
	K�� ���̸� ���� ��� �κй��ڿ��� ���� �ٸ� �ּ��� K�� ã�� �����̴�.
	������ �����Ƿ� ���� ��� �κй��ڿ��� ���� üũ�غ��� �ȴ�.
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