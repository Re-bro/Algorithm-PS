/* [BOJ 20209] 스트레이트 스위치 게임 
	Algorithm : BFS

	5^K의 경우들을 하나의 정점으로 생각하고, 각 스위치를 눌렀을 때 바뀌는 상태를 향하도록 간선을 연결해준다. 
	그리고 처음 주어진 상태에서 시작해서 모든 원소가 같은 지점에 도달하는 최소 횟수를 구한다.
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

int A[10];
int p5[10];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N, K; cin >> N >> K;
	vector<vector<int>> adj(625 * 625, vector<int>());
	vector<vector<int>> swi(10, vector<int>());
	int S = 0;
	p5[0] = 1;
	for (int i = 1; i <= N; i++) p5[i] = p5[i - 1] * 5;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		S += A[i] * p5[i - 1];
	}
	for (int i = 1; i <= K; i++) {
		int a; cin >> a;
		while (a--) {
			int b; cin >> b;
			swi[i].push_back(b);
		}
	}
	for (int i = 0; i < p5[N]; i++) {
		vector<int> tmp(10);
		vector<int> tmp2;
		int k = i;
		int idx = 1;
		while (k > 0) {
			tmp[idx] = k % 5;
			k /= 5;
			idx++;
		}
		for (int j = 1; j <= K; j++) {
			tmp2 = tmp;
			for (int q : swi[j]) 	tmp2[q] += j;
			int val = 0;
			for (int q = 1; q <= N; q++) val += (tmp2[q] % 5)*p5[q - 1];
			adj[i].push_back(val);
		}
	}
	vector<int> dis(625 * 625, MAX);
	queue<pii> q;
	dis[S] = 0;
	q.push({ S, 0 });
	while (!q.empty()) {
		int now = q.front().first;
		int d = q.front().second; q.pop();
		if (d > dis[now]) continue;
		for (int v : adj[now]) {
			if (dis[now] + 1 < dis[v]) {
				dis[v] = dis[now] + 1;
				q.push({ v, dis[v] });
			}
		}
	}
	int ans = MAX;
	int tmp = 0;
	for (int i = 1; i <= N; i++) {
		tmp += p5[i-1];
	}
	for (int i = 0; i <= 4; i++) {
		ans = min(ans, dis[i*tmp]);
	}
	if(ans != MAX) cout << ans;
	else cout << -1;
}
