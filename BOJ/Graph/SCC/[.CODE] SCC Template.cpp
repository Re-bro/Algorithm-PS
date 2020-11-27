/* 
	SCC (Strongly Connected Component) Template
	Based on Tarjan's Algorithm / O(|V| + |E|)
	scc graph (DAG) is sorted topologically by reverse order
	
	Ÿ�� �˰��� ��� SCC �˰��� ���ø�
 	���������� �������� scc��ȣ�� �ο���
*/

#include<bits/stdc++.h>
#define V 10010
using namespace std;

stack<int> S;
vector<vector<int>> adj;
vector<vector<int>> SCC; 
int dfs_n[V] , cnt; //dfs ���� ����
int sn[V]; //���° scc�� ���ԵǾ��ִ���
int SN; //scc ����
int dfs(int u) {
	dfs_n[u] = ++cnt;
	int ret = dfs_n[u];
	S.push(u);
	for (int v : adj[u]) {
		if (dfs_n[v] == 0) ret = min(ret, dfs(v));
		else if (sn[v] == -1) ret = min(ret, dfs_n[v]); //v�� scc�� ���� x
	}
	if (ret == dfs_n[u]) {
		vector<int> tmp;
		while (1) {
			int t = S.top(); S.pop();
			tmp.push_back(t);
			sn[t] = SN;
			if (t == u) break;
		}
		sort(all(tmp)); //���� ��ȣ������ ����
		SCC.push_back(tmp);
		SN++;
	}
	return ret;
}
//SCC �׷���(DAG) ����
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
