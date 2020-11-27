/* 
	SCC (Strongly Connected Component) Template
	Based on Tarjan's Algorithm / O(|V| + |E|)
	scc graph (DAG) is sorted topologically by reverse order
	
	타잔 알고리즘 기반 SCC 알고리즘 템플릿
 	위상정렬의 역순으로 scc번호가 부여됨
*/

#include<bits/stdc++.h>
#define V 10010
using namespace std;

stack<int> S;
vector<vector<int>> adj;
vector<vector<int>> SCC; 
int dfs_n[V] , cnt; //dfs 정점 순서
int sn[V]; //몇번째 scc에 포함되어있는지
int SN; //scc 개수
int dfs(int u) {
	dfs_n[u] = ++cnt;
	int ret = dfs_n[u];
	S.push(u);
	for (int v : adj[u]) {
		if (dfs_n[v] == 0) ret = min(ret, dfs(v));
		else if (sn[v] == -1) ret = min(ret, dfs_n[v]); //v가 scc에 포함 x
	}
	if (ret == dfs_n[u]) {
		vector<int> tmp;
		while (1) {
			int t = S.top(); S.pop();
			tmp.push_back(t);
			sn[t] = SN;
			if (t == u) break;
		}
		sort(all(tmp)); //정점 번호순으로 정렬
		SCC.push_back(tmp);
		SN++;
	}
	return ret;
}
//SCC 그래프(DAG) 생성
void makeDAG(void) {
	sccadj.assign(SN, vector<int>());
	for (int i = 1; i <= V; i++) {
		for (int j : adj[i]) {
			if (sn[i] != sn[j]) sccadj[sn[i]].push_back(sn[j]);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(sn, -1, sizeof(sn));
	for (int i = 1; i <= MAX; i++) {
		if (dfs_n[i] == 0) dfs(i);
	}
	makeDAG();
}
