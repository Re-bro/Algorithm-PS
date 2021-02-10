/* [BOJ 5670] �޴��� ����
	Algorithm : Trie

	�ڵ��Է��� �Ǵ� ������ ���� ��忡�� ������ ���ڿ��� �����鼭,
	�ڽ��� �ϳ��ۿ� ���� ����̴�.
	���� Ʈ���̸� ������ ��, �ڽ��� ���� �����صΰ� 
	���ڿ��� Ž���� �� �ڽ��� ���� 2�̻��̰ų�, ���� ��忡�� ������ �ٸ� ���ڿ��� �ְ�
	�ڽ��� ���� 1�̸� +1�� �ؼ� �Ѱ��ش�.
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
int ans;
struct Trie {
	Trie *ch[26];
	int cnt;
	bool end;
	Trie() {
		for (int i = 0; i < 26; i++) ch[i] = NULL;
		cnt = 0;
		end = false;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
	}
	void insert(const char* s) {
		if (!*s) {
			end = true;
			return;
		}
		int now = *s - 'a';
		if (!ch[now]) {
			ch[now] = new Trie;
			cnt++;
		}
		ch[now]->insert(s + 1);
	}
	void find(const char *s, int k, bool root) {
		if (!*s) {
			ans += k;
			return;
		}
		int now = *s - 'a';
		if (root) ch[now]->find(s + 1, k, false);
		else {
			if (cnt == 1 && !end) ch[now]->find(s + 1, k, false);
			else ch[now]->find(s + 1, k + 1, false);
		}
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n;
	while (cin>>n) {
		Trie *root = new Trie;
		ans = 0;
		vector<string> v;
		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			v.push_back(s);
			root->insert(s.c_str());
		}

		for (string s : v) {
			root->find(s.c_str(), 1, true);
		}
		cout << fixed;
		cout.precision(2);
		cout << (double)ans / sz(v) << '\n';
		delete root;
	}
}