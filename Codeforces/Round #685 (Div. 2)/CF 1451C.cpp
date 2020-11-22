/* Round #685 (Div. 2) C
	Algorithm : Greedy

	문자열의 각 알파벳들을 얼마든지 swap할 수 있으므로 각 알파벳별로 출현 횟수만 따져도 충분하다. 
	각 알파벳을 자신보다 사전순위가 뒤인 알파벳으로만 바꿀 수 있고, k개 단위로 바꿀 수 있다.
	따라서, a부터 z까지 보면서 s1에서 s2로 바꿀 때, s1에서 남은 알파벳들을 k개 단위로 다음 알파벳으로 넘기거나,
	모자란 알파벳은 넘어온 알파벳으로 채워준다. 
	그러지 못한 경우에는 NO를 출력한다. 
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
