/* Round #685 (Div. 2) C
	Algorithm : Greedy

	���ڿ��� �� ���ĺ����� �󸶵��� swap�� �� �����Ƿ� �� ���ĺ����� ���� Ƚ���� ������ ����ϴ�. 
	�� ���ĺ��� �ڽź��� ���������� ���� ���ĺ����θ� �ٲ� �� �ְ�, k�� ������ �ٲ� �� �ִ�.
	����, a���� z���� ���鼭 s1���� s2�� �ٲ� ��, s1���� ���� ���ĺ����� k�� ������ ���� ���ĺ����� �ѱ�ų�,
	���ڶ� ���ĺ��� �Ѿ�� ���ĺ����� ä���ش�. 
	�׷��� ���� ��쿡�� NO�� ����Ѵ�. 
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

int A[26], B[26];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		string s1, s2; cin >> s1 >> s2;
		ini(A, 0);
		ini(B, 0);
		for (int i = 0; i < n; i++) {
			A[s1[i] - 'a']++;
			B[s2[i] - 'a']++;
		}
		int r = 0;
		bool check = true;
		for (int i = 0; i < 26; i++) {
			if (A[i] + r < B[i]) {
				check = false;
				break;
			}
			else {
				r -= B[i] - A[i];
				r = (r / k)*k;
			}
		}
		if (check) cout << "Yes\n";
		else cout << "No\n";
	}
}
