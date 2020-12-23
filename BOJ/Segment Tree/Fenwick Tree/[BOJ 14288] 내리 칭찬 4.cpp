/* [BOJ 14288] ���� Ī�� 4
	Algorithm : Lazy propagation / Fenwick Tree

	Ī���� ������ �������� �����̸� �̸� ��ó���ص� dfs �ѹ��� ���ؼ� �� ��������
	L[i] ~ R[i] ��ŭ ���� ������Ʈ�� �����ָ� �ȴ�.
	Ī���� ������ �������̸�, ���� ������ �ڼ����� �ϴ� ��� ��翡 �������� ���̹Ƿ�
	L[i] �� ������Ʈ�� �����ָ� �ȴ�. 

*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int>adj[100001];
int L[100001], R[100001], tr[100001], tr2[100001];
int num = 0;
void dfs(int u) {
	L[u] = ++num;
	for (int v : adj[u]) {
		dfs(v);
	}
	R[u] = num;
}
void update(int tr[], int i, int val) {
	while (i <= n) {
		tr[i] += val;
		i += (i & -i);
	}
}
int sum(int tr[], int i) {
	int ans = 0;
	while (i > 0) {
		ans += tr[i];
		i -= (i & -i);
	}
	return ans;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (a != -1) adj[a].push_back(i);
	}
	dfs(1);
	bool down = true;
	for (int i = 1; i <= m; i++) {
		int a; cin >> a;
		if (a == 1) {
			int b, c; cin >> b >> c;
			if (down) {
				update(tr, L[b], c);
				update(tr, R[b] + 1, -c);
			}
			else {
				if (L[b] < R[b]) {
					update(tr2, L[b], c);
				}
			}
		}
		else if(a == 2){
			int b; cin >> b;
			cout<<sum(tr, L[b]) + sum(tr2, R[b]) - sum(tr2, L[b]-1)<<'\n';
		}
		else {
			down ^= 1;
		}
	}
}