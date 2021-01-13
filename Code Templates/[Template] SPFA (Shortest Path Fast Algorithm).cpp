/* SPFA (Shortest Path Fast Algorithm) Template
	√÷æ« : O(VE)
	∆Ú±’ : O(V + E) or O(E)
*/

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define MAX_V 10001
vector<pii> adj[MAX_V];
bool inQ[MAX_V];
int dis[MAX_V], cycle[MAX_V];
int S; //start
int n, m; //n = vertex, m = edge number 

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	fill(dis, dis + MAX_V, 1e9);
	queue<int> q;
	dis[S] = 0; inQ[S] = true; cycle[S]++;
	q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inQ[u] = false;
		for (pii p : adj[u]) {
			int v = p.first;
			int cost = p.second;
			if (dis[v] > dis[u] + cost) {
				dis[v] = dis[u] + cost;
				if (!inQ[v]) {
					cycle[v]++;
					if (cycle[v] >= n) return cout << "cycle", 0;
				}
				q.push(v);
				inQ[v] = true;
			}
		}
	}
}