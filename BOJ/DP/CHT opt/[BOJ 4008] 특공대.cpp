/* [BOJ 4008] Æ¯°ø´ë
	Algorithm : CHT
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll x[1000001];
ll dp[1000001];
int n;
ll a, b, c;
double isect(int i, int j) {
	ll k = a * (x[j] * x[j] - x[i] * x[i]) - b * (x[j] - x[i]) + dp[j] - dp[i];
	return k / (2.0 * a * (x[j] - x[i]));
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> a >> b >> c;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		x[i] += x[i - 1];
	}
	deque<int> L;
	L.push_back(0);
	for (int i = 1; i <= n; i++) {
		while (L.size() > 1 && isect(L[0], L[1]) < x[i]) L.pop_front();
		int k = L.front();
		dp[i] = -2 * a * x[k] * x[i] + a * x[k] * x[k] - b * x[k] + dp[k] + a * x[i] * x[i] + b * x[i] + c;
		while (L.size() > 1 && isect(i, L[L.size() - 2]) < isect(L[L.size() - 2], L.back())) L.pop_back();
		L.push_back(i);
	}
	cout << dp[n];
}