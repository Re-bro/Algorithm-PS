/* [BOJ 18783] Swapity Swapity Swap
	Algorithm : sparse array
	
	����, N�� 10���̰�, �־����� ������ 100���̹Ƿ�
	ù��° step���� ���� ������ ����� ���� ���Ѵ�. 
	�� �迭�� P��� �ϸ�, �� �������� ����Ǵ� ������ �迭�� ���� P�� ����� �۾��̴�.
	���� �ᱹ �־��� ������ K�� �������� �� ������ ����� �ٲ�� �ǹǷ�, 
	�� ���Ҹ��� �ڽ��� ���� ����Ŭ�� ���Ѵ��� ����Ŭ���� ���Ҹ� ������� �־��� ��, 
	(K%����Ŭ�� ���� ���� ����) �� ���� ã���ش�.  
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
using pii = pair<int, int>;

int ans[100001];
int P[100001];
pii num[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N, M, K; cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		P[i] = i;
		ans[i] = i;
	}
	for (int i = 1; i <= M; i++) {
		int l, r; cin >> l >> r;
		reverse(P + l, P + r + 1);
	}
	int n = 1;
	vector<vector<int>> v(N + 1, vector<int>());
	for (int i = 1; i <= N; i++) {
		if (num[i].first != 0) continue;
		int k = P[i];
		int idx = 0;
		num[i] = { n, idx++};
		v[n].push_back(i);
		int cnt = 1;
		while (k != i) {
			num[k] = { n, idx++ };
			v[n].push_back(k);
			k = P[k];
			cnt++;
		}
		n++;
	}
	for (int i = 1; i <= N; i++) {
		cout << v[num[i].first][(num[i].second + K) % sz(v[num[i].first])] << '\n';
	}
}