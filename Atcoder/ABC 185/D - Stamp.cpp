#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);
int A[200010];
int N, M;
bool sol(int val) {
	for (int i = 1; i <= M + 1; i++) {
		if (A[i] - A[i - 1] >= 2 && A[i] - A[i - 1] - 1 < val) return false;
	}
	return true;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> A[i];
	if (M == 0) {
		cout << 1;
		return 0;
	}
	sort(A + 1, A + 1 + M);
	A[M + 1] = N + 1;
	int s = 1;
	int e = N;
	int ans = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (sol(mid)) {
			ans = max(ans, mid);
			s = mid + 1;
		}
		else e = mid - 1;
	}
	int res = 0;
	for (int i = 1; i <= M + 1; i++) {
		res += (A[i] - A[i - 1] - 1) / ans + ((A[i] - A[i - 1] - 1) % ans == 0 ? 0 : 1);
	}

	cout << res;
}