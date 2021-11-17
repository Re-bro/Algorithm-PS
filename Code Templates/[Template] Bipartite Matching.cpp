/*O(VE)*/

#include<bits/stdc++.h>
using namespace std;

#define MAX 1000 // A쪽의 원소 개수
#define NUM 1000 //B쪽의 원소 개수

vector<vector<int>>adj(MAX);

int P[NUM];
bool visited[MAX];
bool dfs(int u) {
	if (visited[u]) return false;
	visited[u] = true;
	for (int v : adj[u]) {
		if (P[v] == -1 || dfs(P[v])) {
			P[v] = u;
			return true;
		}
	}
	return false;
}

int main(void) {
	int res = 0;
	memset(P, -1, sizeof(P));
	for (int i = 1; i <= MAX; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) res++;
	}
	cout << res;
}
