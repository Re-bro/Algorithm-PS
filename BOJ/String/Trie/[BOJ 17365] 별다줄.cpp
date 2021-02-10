/* [BOJ 17365] ������
	Algorithm : Trie / DP

	������ ��� �ܾ Ʈ���̿� ���� ��, �� ��忡������ ��������� �ܾ��� ���� �����صд�.
	�׸���, �ؼ��Ϸ��� �ܾ��� �� �ڸ��������� ���� �� �ִ� �ܾ��� ������ dp�� �����Ѵ�.
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll dp[200001];
string st;
struct Trie {
	Trie * ch[26];
	int cnt;
	Trie() {
		cnt = 0;
		for (int i = 0; i < 26; i++) ch[i] = NULL;
	}
	void insert(const char *s) {
		cnt++;
		if (!*s) return;
		int now = *s - 'a';
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(s + 1);
	}
};
Trie *root;
ll sol(int idx) {
	if (idx == sz(st)) return 1;
	ll &res = dp[idx];
	if (res != -1) return res;
	res = 0;
	int k = 0;
	Trie *now = root;
	while (1) {
		if (idx + k == sz(st)) break;
		if (!(now->ch[st[idx + k] - 'a'])) break;
		now = now->ch[st[idx + k] - 'a'];
		res += (now->cnt)*sol(idx + k+1);
		res %= MOD;
		k++;
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	root = new Trie;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		root->insert(s.c_str());
	}
	cin >> st;
	ini(dp, -1);
	cout << sol(0);
}