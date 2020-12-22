/* [BOJ 16404] �ֽ�ȸ�� �¹��̳�
	Algorithm : Segment Tree or Fenwick Tree / Euler-tour technique

	dfs �湮 ������� �������� ��ȣ�� �ű��, �� �������� �ڽ��� �ڽĵ��� ��ȣ ������ ���س��´�.
	���� ���� ������ ��ȣ�� 3�̰�, �ڼյ��� ��ȣ�� 7���� �ִٸ� 
	�ش� ������ 3~7�� ������ �����ϰ� �Ǵ� ���̴�. 
	���� ���Ŀ� ���׸�Ʈ Ʈ�� (Range update) �� �̿����ش�.
*/

#include<bits/stdc++.h>
using namespace std;
int tr[100001];
int N, M;
int sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += tr[i];
		i -= (i&-i);
	}
	return ans;
}
void update(int i, int val) {
	while (i < N + 1) {
		tr[i] += val;
		i += (i&-i);
	}
}
vector<int>adj[100001];
int num = 0;
int L[100001], R[100001];
void dfs(int u) {
	L[u] = ++num;
	for (int v : adj[u]) {
		dfs(v);
	}
	R[u] = num;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		if (a != -1) {
			adj[a].push_back(i);
		}
	}
	dfs(1);
	for (int i = 1; i <= M; i++) {
		int a; cin >> a;
		if (a == 1) {
			int b, c; cin >> b >> c;
			update(L[b], c);
			update(R[b] + 1, -c);
		}
		else {
			int b; cin >> b;
			cout << sum(L[b]) << '\n';
		}
	}
}