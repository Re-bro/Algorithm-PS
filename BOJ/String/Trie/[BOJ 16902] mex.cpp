/* [BOJ 16902] mex
	Algorithm : Trie

	수열 A의 원소에 xor을 해서 바꿔가는 것이 아니라, 쿼리로 주어지는 x를 xor해서 바꿔간다. 
	수열 A의 원소는 변하지 않으므로 원소들의 값을 트라이에 미리 넣어준다. 
	현재 쿼리 'x'를 탐색할 때, 만약 현재 노드가 i번째 bit를 나타내는 노드이고, 
	이로부터 이후의 모든 노드에 도달할 수 있다면, 0 ~ (1<<i) -1 범위내의 값들은 모두 수열에 남게 된다. 
	반면 도달하지 못하는 노드가 있다면 해당 값은 수열에 존재하지 않는다.
	이 값중 최솟값을 출력해낸다. 
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e9;

bool visited[300001];
int ans;
struct Trie {
	Trie* ch[2];
	int cnt;
	Trie() {
		ch[0] = ch[1] = NULL;
		cnt = 0;
	}
	void insert(int a, int p) {
		cnt++;
		if (p == 0) return;
		int k = (a & (1 << (p - 1))) ? 1 : 0;
		if (!ch[k]) ch[k] = new Trie;
		ch[k]->insert(a, p - 1);
	}
	int find(int a, int p) {
		if (p == 0) return MAX;
		int k = (a & (1 << (p - 1))) ? 1 : 0;
		int val = MAX;
		if (cnt == (1 << p)) return MAX;
		if (ch[k]) {
			val = min(ch[k]->find(a, p - 1), val);
			if (!ch[(k + 1) % 2]) val = min(val, (1 << (p - 1)));
			else {
				if (val == MAX) val = min(val, (1 << (p - 1)) + ch[(k + 1) % 2]->find(a, p - 1));
			}
			return val;
		}
		else return 0;
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M; cin >> N >> M;
	Trie* root = new Trie;
	for (int i = 1; i <= N; i++) {
		int a; cin >> a;
		if (!visited[a]) {
			root->insert(a, 20);
			visited[a] = true;
		}
	}
	int xo = 0;
	for (int i = 1; i <= M; i++) {
		int x; cin >> x;
		xo ^= x;
		ans = MAX;
		cout << root->find(xo, 20) << '\n';
	}
}