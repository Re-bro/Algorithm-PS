/* [BOJ 16903] 수열과 쿼리 20
	Algorithm : Trie

	두 수 XOR 문제에서 원소를 제거하는 쿼리가 추가된 문제이다. 
	원소를 추가할 때는, 해당 노드에 cnt++을 해주고, 원소를 제거할땐 cnt--를 해주어
	해당 노드로 갈 수 있는지를 판단할 때에는 노드가 생성이 되어있고, cnt > 0을 만족하는지를 체크한다.
*/

#include<bits/stdc++.h>
using namespace std;
struct Trie {
	Trie *ch[2];
	int cnt;
	Trie() {
		ch[0] = ch[1] = NULL;
		cnt = 0;
	}
	void insert(int a, int p, bool del) {
		if(!del) cnt++;
		else cnt--;
		if (p == 0) return;
		int k = (a& (1 << (p - 1))) ? 1 : 0;
		if (!ch[k]) ch[k] = new Trie;
		ch[k]->insert(a, p - 1, del);
	}
	int find(int a, int p) {
		if (cnt == 0) return a;
		if (p == 0) return 0;
		int k = (a&(1 << (p - 1))) ? 1 : 0;
		int k2 = (k + 1) % 2;
		if (ch[k2] && ch[k2]->cnt > 0) return ch[k2]->find(a, p - 1) + (1 << (p - 1));
		else {
			return ch[k]->find(a, p - 1);
		}
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int M; cin >> M;
	Trie * root = new Trie;
	root->insert(0, 31, false);
	for (int i = 1; i <= M; i++) {
		int a, b; cin >> a >> b;
		if (a == 1) root->insert(b, 31, false);
		else if (a == 2) root->insert(b, 31, true);
		else 	cout << root->find(b, 31) << '\n';
	}
}