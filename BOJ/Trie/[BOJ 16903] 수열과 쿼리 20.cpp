/* [BOJ 16903] ������ ���� 20
	Algorithm : Trie

	�� �� XOR �������� ���Ҹ� �����ϴ� ������ �߰��� �����̴�. 
	���Ҹ� �߰��� ����, �ش� ��忡 cnt++�� ���ְ�, ���Ҹ� �����Ҷ� cnt--�� ���־�
	�ش� ���� �� �� �ִ����� �Ǵ��� ������ ��尡 ������ �Ǿ��ְ�, cnt > 0�� �����ϴ����� üũ�Ѵ�.
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