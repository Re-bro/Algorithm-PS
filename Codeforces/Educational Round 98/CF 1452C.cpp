/* CF Educational round 98 C
	Algorithm : Greedy

	�Ұ�ȣ�� ���ȣ�� ���� �����ؼ�, �ݴ� ��ȣ�� ���� ��, 
	������ ���� ���� ��ȣ�� �ִ� ��쿡 ���� 1 ���������ְ�
	���� ��ȣ�� ������ 1�� ���ҽ����ش�.	
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);


int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		int cnt1 = 0;
		int cnt2 = 0;
		int ans = 0;
		for (int i = 0; i < sz(s); i++) {
			if (s[i] == '(') cnt1++;
			else if (s[i] == ')') {
				if (cnt1 >= 1) {
					ans++;
					cnt1--;
				}
			}
			else if (s[i] == '[') {
				cnt2++;
			}
			else {
				if (cnt2 >= 1) {
					ans++;
					cnt2--;
				}
			}
		}
		cout << ans << '\n';
	}
}
