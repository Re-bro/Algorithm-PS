/* [BOJ 13504] XOR ��
	Algorithm : Trie

	�κ� ������ XOR���� �ΰ��� prefix xor�� ���� �� �ִ�. 
	���� �� [i, j]������ XOR ���� prefix[j] ^ prefix[i-1] �̴�.
	���� prefix[0] ~ prefix[N]�� ��� Ʈ���̿� �ְ�, 
	prefix[0]���� prefix[N]���� ���ʴ�� Ž���غ��� �ִ��� �κ� ������ ���� �� �ִ�.
	prefix[i]�� �ϳ��� ���� ���ٸ� �� �� XOR ������ �����ϴ�.
*/

#include<bits/stdc++.h>

using namespace std;
int pxo[100001];
struct Trie {
	Trie *ch[2];
	Trie() {
		ch[0] = ch[1] = NULL;
	}
	~Trie() {
		if (ch[0]) delete ch[0];
		if (ch[1]) delete ch[1];
	}
	void insert(int a, int p) {
		if (p == 0) return;
		int k = (a&(1 << (p - 1))) ? 1 : 0;
		if (!ch[k]) ch[k] = new Trie;
		ch[k]->insert(a, p - 1);
	}
	int find(int a, int p) {
		if (p == 0) return 0;
		int k = (a & (1 << (p - 1))) ? 1 : 0;
		if (k == 1) {
			if (ch[0]) return ch[0]->find(a, p - 1) + (1 << (p - 1));
			else return ch[1]->find(a, p - 1);
		}
		else {
			if (ch[1]) return ch[1]->find(a, p - 1) + (1 << (p - 1));
			else return ch[0]->find(a, p - 1);
		}
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		Trie *root = new Trie;
		for (int i = 1; i <= N; i++) {
			int a; cin >> a;
			pxo[i] = pxo[i - 1] ^ a;
		}
		for (int i = 1; i <= N; i++) {
			root->insert(pxo[i], 31);
		}
		int ans = 0;
		for (int i = 0; i <= N; i++) {
			ans = max(ans, root->find(pxo[i], 31));
		}
		cout << ans << '\n';
		delete root;
	}

}