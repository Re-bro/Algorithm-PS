/* [BOJ 18783] Swapity Swapity Swap
	Algorithm : sparse array
	
	먼저, N이 10만이고, 주어지는 구간이 100개이므로
	첫번째 step으로 인해 나오는 결과는 직접 구한다. 
	이 배열을 P라고 하면, 그 다음부터 진행되는 과정은 배열에 순열 P를 씌우는 작업이다.
	따라서 결국 주어진 순열을 K번 적용했을 때 나오는 결과로 바뀌게 되므로, 
	각 원소마다 자신이 속한 사이클을 구한다음 사이클마다 원소를 순서대로 넣어준 후, 
	(K%사이클에 속한 원소 개수) 로 값을 찾아준다.  
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