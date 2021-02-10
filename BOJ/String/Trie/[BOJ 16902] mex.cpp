/* [BOJ 16902] mex
	Algorithm : Trie

	���� A�� ���ҿ� xor�� �ؼ� �ٲ㰡�� ���� �ƴ϶�, ������ �־����� x�� xor�ؼ� �ٲ㰣��. 
	���� A�� ���Ҵ� ������ �����Ƿ� ���ҵ��� ���� Ʈ���̿� �̸� �־��ش�. 
	���� ���� 'x'�� Ž���� ��, ���� ���� ��尡 i��° bit�� ��Ÿ���� ����̰�, 
	�̷κ��� ������ ��� ��忡 ������ �� �ִٸ�, 0 ~ (1<<i) -1 �������� ������ ��� ������ ���� �ȴ�. 
	�ݸ� �������� ���ϴ� ��尡 �ִٸ� �ش� ���� ������ �������� �ʴ´�.
	�� ���� �ּڰ��� ����س���. 
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