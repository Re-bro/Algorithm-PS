/* Round #686 (Div. 3) F
	Algorithm : Segment Tree / Prefix sum / Binary Search

	우선 최솟값은, 원소를 추가하게 되면 감소만 가능하고, 원소를 제거하면 증가만 가능하다.
	최댓값은 원소를 추가하게 되면 증가만 가능하고, 원소를 제거하면 감소만 가능하다.
	이를 이용해서, 최댓값을 prefix sum의 형태로 구현하면, 항상 비내림차순으로 나오게 된다. 
	x를 고정시킨 후, y에 해당할 지점을 이분탐색으로 구한다. 
	만약 min(x+1, x+y) < max(1, x)인 경우는 min 구간의 원소를 제거해주어야 하므로 y를 왼쪽으로 이동시킨다.
	min(x+1, x+y) > max(1, x)인 경우는 y를 오른쪽으로 이동시켜준다. 
	max(x+y+1, n)은 미리 구해놓은 prefix max의 역순을 통해서 O(1)만에 구해낼 수 있다.

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

int A[200001];
int tr[800001];
int mx[200001];
int init(int x, int s, int e) {
	if (s == e)return tr[x] = A[s];
	else {
		return tr[x] = min(init(x * 2, s, (s + e) / 2), init(x * 2 + 1, (s + e) / 2 + 1, e));
	}
}
int min_(int x, int s, int e, int l, int r) {
	if (s > r || e < l) return MAX;
	else if (s >= l && e <= r) return tr[x];
	else return min(min_(x * 2, s, (s + e) / 2, l, r), min_(x * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> A[i];
		init(1, 1, n);
		mx[0] = 0;
		for (int i = n; i >= 1; i--) {
			mx[n - i + 1] = max(mx[n - i], A[i]);
		}
		int M = 0;
		int a, b, c;
		bool chk = false;
		for (int i = 1; i <= n - 2; i++) {
			M = max(M, A[i]);
			int s = i + 1;
			int e = n - 1;
			while (s <= e) {
				int mid = (s + e) / 2;
				int k = min_(1, 1, n, i+1, mid);
				if (M == k && k == mx[n - mid]) {
					chk = true;
					a = i;
					b = mid - i;
					c = n - mid;
					break;
				}
				else if (M < mx[n - mid]) s = mid+1;
				else if (M > mx[n - mid]) e = mid-1;
				else {
					if (k > M) s = mid+1;
					else e = mid-1;
				}
			}
			if (chk) break;
		}
		if (chk) {
			cout << "YES\n";
			cout << a << ' ' << b << ' ' << c << '\n';
		}
		else cout << "NO\n";
	}
}