/* [BOJ 13504] XOR 합
	Algorithm : Trie

	부분 수열의 XOR합은 두개의 prefix xor로 구할 수 있다. 
	예를 들어서 [i, j]구간의 XOR 합은 prefix[j] ^ prefix[i-1] 이다.
	따라서 prefix[0] ~ prefix[N]을 모두 트라이에 넣고, 
	prefix[0]부터 prefix[N]까지 차례대로 탐색해보면 최대의 부분 수열을 구할 수 있다.
	prefix[i]를 하나의 수로 본다면 두 수 XOR 문제와 동일하다.
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