/*
	[BOJ 12766] ���� ����
	Algorithm : DnC opt / Dijkstra

	to : ���� -> ���� / from : ���� -> ����
	�� �׷��� ���� �� == k  => �ش� �׷��� �̵� �Ÿ� == (k-1) * (sum of (to + from))
	dp[i][j] : i���� �׷����� j��° ������� ���� �ּ� ���
	dp[i][j] = min(dp[i-1][k] + (j-k)*(cost[k+1] ~ cost[j])) (k<j)

	���縦 ���α����� �պ� �Ÿ��� ���������� �ǵ��� ������ ��, 
	C[a][b] = b��° ������� a���� �׷����� ���� �ּ� ��� �̶�� �ϸ� C�� monge array�� �����Ѵ�. 
*/



#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
#define fi first
#define se second

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const ll MAX = (ll)1e18;
const double PI = acos(-1);

int n, b, s, r;
vector<pii> adj[5001], adj2[5001];
vector<ll> to, from, cost;
ll dp[5001][5001]; 
void dnc(int t, int s, int e, int l, int r) {
	if (s > e) return;
	int m = (s + e) / 2;
	int opt = l;
	for (int i = l; i <= r; i++) {
		if (dp[t - 1][opt-1] + (m - opt)*(cost[m] - cost[opt-1]) > dp[t - 1][i-1] + (m - i)*(cost[m] - cost[i-1])) opt = i;
	}
	dp[t][m] = dp[t - 1][opt-1] + (m - opt)*(cost[m] - cost[opt-1]);
	dnc(t, s, m - 1, l, opt);
	dnc(t, m + 1, e, opt, r);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n >> b >> s >> r;
	for (int i = 1; i <= r; i++) {
		int u, v, l; cin >> u >> v >> l;
		adj[u].push_back({ v, l });
		adj2[v].push_back({ u, l });
	}
	to.assign(5001, MAX);
	to[b + 1] = 0;
	priority_queue<pll> pq;
	pq.push({ 0, b + 1 });
	while (!pq.empty()) {
		auto[c, now] = pq.top(); pq.pop();
		if (to[now] < -c) continue;
		for (auto[v, cost] : adj[now]) {
			if (to[v] > -c + cost) {
				to[v] = -c + cost;
				pq.push({ -to[v], v });
			}
		}
	}
	from.assign(5001, MAX);
	from[b + 1] = 0;
	pq.push({ 0, b + 1 });
	while (!pq.empty()) {
		auto[c, now] = pq.top(); pq.pop();
		if (from[now] < -c) continue;
		for (auto[v, cost] : adj2[now]) {
			if (from[v] > -c + cost) {
				from[v] = -c + cost;
				pq.push({ -from[v], v });
			}
		}
	}
	cost.assign(5001, 0);
	for (int i = 1; i <= b; i++) cost[i] = to[i] + from[i];
	sort(cost.begin()+1, cost.begin()+1+b);
	for (int i = 1; i <= b; i++) cost[i] += cost[i - 1];
	for (int i = 1; i <= b; i++) dp[1][i] = (i-1) * cost[i];
	for (int i = 2; i <= s; i++) dnc(i, i, b, i, b);
	cout << dp[s][b];
}