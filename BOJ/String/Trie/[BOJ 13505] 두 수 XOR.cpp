/* [BOJ 13505] �� �� XOR
	Algorithm : Trie

	�Է¹��� ��� ������ Ʈ���̿� �־����, �� ������ Ʈ���̿���
	�ڽ��� bit�� �ݴ�Ǵ� ��尡 �ִٸ� �� ��带 Ÿ�� ����. 
	�� ��찡 �� ���Һ��� �ִ��� XOR���� ã�� ����̴�.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);
int A[100001];
struct Trie {
	Trie* ch[2];
	bool idx;
	Trie() {
		ch[0] = ch[1] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 2; i++) if (ch[i]) delete ch[i];
	}
	void insert(int a, int p) {
		if (p == 0) return;
		int k = (a & (1 << (p - 1))) ? 1 : 0;
		if (!ch[k]) ch[k] = new Trie;
		ch[k]->insert(a, p - 1);
	}
	int find(int a, int p) {
		if (p == 0) return 0;
		if (a & (1 << (p-1))) {
			if (ch[0]) {
				return ch[0]->find(a, p - 1) + (1 << (p-1));
			}
			else if (ch[1]) {
				return ch[1]->find(a, p - 1);
			}
			else return 0;
		}
		else {
			if (ch[1]) {
				return ch[1]->find(a, p - 1) + (1 << (p-1));
			}
			else if (ch[0]) return ch[0]->find(a, p - 1);
			else return 0;
		}
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	Trie* root = new Trie;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		root->insert(A[i], 31);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, root->find(A[i], 31));
	}
	cout << ans;
}