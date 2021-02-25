/*
	[BOJ 11001] 김치
	Algorithm : Dnc Opt

	dp[i] : i일에 김치를 꺼낼 때, 얻을 수 있는 가장 높은 값
	dp[i] = max(v[j] + (i - j)*t[i])   (i-d <= j <= i)

	C(j, i) = v[j] + (i - j)*t[i] 라고 하면, monge array 성질을 만족한다.
*/

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll t[100001], v[100001];
ll dp[100001];
int n, d;
void dnc(int s, int e, int l, int r) {
	if (s > e) return;
	int m = (s + e) / 2;
	int opt = l;
	for (int i = max(l, m-d); i <= r; i++) {
		if (v[i] + (m - i)*t[m] > dp[m]) {
			opt = i;
			dp[m] = v[i] + (m - i)*t[m];
		}
	}
	dnc(s, m - 1, l, opt);
	dnc(m + 1, e, opt, r);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int i = 1; i <= n; i++) cin >> v[i], dp[i] = v[i];
	dnc(1, n, 1, n);
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans;
}