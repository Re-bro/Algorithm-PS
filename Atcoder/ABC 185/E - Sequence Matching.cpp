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
int A[1001];
int B[1001];
int N, M;
int dp[1001][1001];
int sol(int a, int b) {
	if (a == N || b == M) {
		int ret = M - b + N - a;
		return ret;
	}
	int &ret = dp[a][b];
	if (ret != -1) return ret;
	ret = MAX;
	ret = min(ret, sol(a + 1, b) + 1);
	ret = min(ret, sol(a, b + 1) + 1);
	ret = min(ret, sol(a + 1, b + 1) + (A[a+1] != B[b+1] ? 1 : 0));
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= M; i++) cin >> B[i];
	ini(dp, -1);
	cout << sol(0, 0);
}