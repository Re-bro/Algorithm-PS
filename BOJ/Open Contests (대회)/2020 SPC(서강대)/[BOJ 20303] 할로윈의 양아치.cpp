/* [BOJ 20303] 할로윈의 양아치
	Algorithm : Union-Find, Knapsack, DP

	풀이 : https://wogud6792.tistory.com/78
*/


#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
using pii = pair<int, int>;

int c[30001];
pii P[30001];
int dp[3001];
int find(int a) {
	if (P[a].first < 0) return a;
	else return P[a].first = find(P[a].first);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (P[a].first > P[b].first) swap(a, b);
		P[a].first += P[b].first;
		P[a].second += P[b].second;
		P[b].first = a;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M, K; cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> c[i];
	for (int i = 1; i <= N; i++) {
		P[i].first = -1;
		P[i].second = c[i];
	}
	for (int i = 1; i <= M; i++) {
		int a, b; cin >> a >> b;
		merge(a, b);
	}
	vector<pii> v;
	for (int i = 1; i <= N; i++) {
		if (P[i].first < 0) {
			v.push_back({ -P[i].first, P[i].second });
		}
	}
	for (int i = 0; i < sz(v); i++) {
		for (int j = K - 1; j >= v[i].first; j--) {
			dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
		}
	}
	int ans = 0;
	for (int i = 1; i < K; i++) ans = max(ans, dp[i]);
	cout << ans;
}