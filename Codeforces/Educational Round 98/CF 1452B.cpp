/* CF Educational round 98 B
	Algorithm : Math / Sorting

	��� index�� �̴��� block�� ��� ���� ���̸�ŭ ä��� ���ؼ���
	max = A[i]�� �ִ��̶�� �ϸ�, ��� max ��ŭ�� �� block�� ä������ �Ѵ�. 
	���� max*(n-1)�� total���� ũ�ٸ� ��� block�� max��ŭ ä��� �ǰ�,
	total�� max*(n-1)���� ũ�ٸ� block�� ���̰� max���� �������� ������ �׸�ŭ �� �ʿ��ϴ�. 
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
