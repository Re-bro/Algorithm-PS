/* Bellman-Ford Algorithm */
//O(VE)
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int N;
vector<pii>adj[1000];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	vector<int> dis(N + 1, 1e9);
	dis[1] = 0;
	bool updated;
	for (int i = 1; i <= N; i++) {
		updated = false;
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < adj[j].size(); k++) {
				int next = adj[j][k].first;
				int cost = adj[j][k].second;
				if (dis[next] > dis[j] + cost) {
					dis[next] = dis[j] + cost;
					updated = true;
				}
			}
		}
		if (!updated) break;
	}
}

