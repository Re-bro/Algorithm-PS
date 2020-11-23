/* [BOJ 20209] ��Ʈ����Ʈ ����ġ ���� 
	Algorithm : Brute-Force / Backtracking

	����ġ�� 5���� ������ �ѹ��� ������ ���� �Ͱ� ����.
	���� �� ����ġ���� 0 ~ 4�� ���� ���, �� 5^K���� ��츦 ��� Ž���Ѵ�.
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

int N, K;
int A[10];
vector<vector<int>> swi;
int ans = MAX;
void sol(int idx, int cnt) {
	if (idx > K) {
		bool check = true;
		for (int i = 2; i <= N; i++) {
			if (A[1] != A[i]) check = false;
		}
		if (check) {
			ans = min(ans, cnt);
		}
		return;
	}
	sol(idx + 1, cnt);
	for (int i = 1; i <= 4; i++) {
		for (int j : swi[idx]) A[j] = (A[j] + idx) % 5;
		sol(idx + 1, cnt + i);
	}
	for (int j : swi[idx]) A[j] = (A[j] - idx * 4 + 100000) % 5;
	return;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	swi.assign(K + 1, vector<int>());
	for (int i = 1; i <= K; i++) {
		int n; cin >> n;
		while (n--) {
			int a; cin >> a;
			swi[i].push_back(a);
		}
	}
	sol(1, 0);
	if (ans == MAX) cout << -1;
	else cout << ans;
}
