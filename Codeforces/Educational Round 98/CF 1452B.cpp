/* CF Educational round 98 B
	Algorithm : Math / Sorting

	어떠한 index를 뽑더라도 block을 모두 같은 높이만큼 채우기 위해서는
	max = A[i]중 최댓값이라고 하면, 적어도 max 만큼은 각 block이 채워져야 한다. 
	따라서 max*(n-1)이 total보다 크다면 모든 block을 max만큼 채우면 되고,
	total이 max*(n-1)보다 크다면 block의 높이가 max보다 높아지기 때문에 그만큼 더 필요하다. 
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

ll A[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		ll total = 0;
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			total += A[i];
		}
		sort(A + 1, A + 1 + n);
		if (total > A[n] * (n - 1)) A[n] = (total + n - 2) / (n - 1);
		cout << A[n] * (n - 1) - total << '\n';
	}
}
