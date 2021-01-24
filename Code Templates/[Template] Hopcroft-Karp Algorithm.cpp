#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;
struct hopcroft_karp {
	int n; //n : �� �׷� �� �� ū ũ��
	//A[i], B[i] : �׷��� i�� ������ ��Ī�� ����� �׷� ���� ��ȣ
	//dist[i] : A �׷��� i�� ���� ����
	//match[i] : A �׷��� i�� ������ ��Ī ����
	vector<int> A, B, dist, match, see;
	vector<vector<int>>adj;
	hopcroft_karp(int n) : n(n) {
		A.assign(n + 1, -1);
		B.assign(n + 1, -1);
		dist.assign(n + 1, 0);
		match.assign(n + 1, 0);
		adj.resize(n + 1);
	}
	void addedge(int u, int v) {
		adj[u].push_back(v);
	}
	void bfs() {
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (!match[i]) {
				dist[i] = 0;
				q.push(i);
			}
			else dist[i] = MAX;
		}
		//BFS�� ���ؼ� A�׷� ������ 0, 1, 2, ... ������ �ű�
		while (!q.empty()) {
			int a = q.front(); q.pop();
			for (int b : adj[a]) {
				//B������ b�� ��Ī�� �Ǿ��ְ�, ��Ī�� A ������ level�� ����
				if (B[b] != -1 && dist[B[b]] == MAX) {
					dist[B[b]] = dist[a] + 1;
					q.push(B[b]);
				}
			}
		}
	}
	//�� ��Ī�� ã���� true
	bool dfs(int u) {
		for (; see[u] < (int)adj[u].size(); see[u]++) {
			int v = adj[u][see[u]];
			if (B[v] == -1 || (dist[B[v]] == dist[u] + 1 && dfs(B[v]))) {
				match[u] = true;
				A[u] = v;
				B[v] = u;
				return true;
			}
		}
		return false;
	}
	int solve() {
		int ret = 0;
		while (1) {
			see.assign(n + 1, 0);
			bfs();
			int flow = 0;
			for (int i = 1; i <= n; i++) {
				if (!match[i] && dfs(i)) flow++;
			}
			if (!flow) break;
			ret += flow;
		}
		return ret;
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	hopcroft_karp hk(n);
	hk.addedge(u, v);
	cout << hk.solve();
}