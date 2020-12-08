/* [BOJ 5446] �뷮 ����
	Algorithm : Trie

	��� ���ϸ���� Ʈ���̿� �ְ�, ����� �ȵǴ� ���ϸ��� �ش� ���ϸ��� �����ϴ�
	��忡�� ����� �ȵȴٴ� ǥ�ø� �صд�. (no ����)
	�׷���, ��带 Ÿ�� ���ٰ� no������ false�̸� ���� ������ ������� ������ �ȴٴ� �ǹ��̹Ƿ�
	����� Ƚ���� 1�� return ���ش�.
	���� ���� ����� no������ true�̴���, �������ϴ� ���ϸ��� ���̸� 1�� ������� �ϴ����� ��������.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);

struct Trie {
	Trie* ch[65];
	bool no;
	bool end;
	Trie() {
		no = false;
		end = false;
		for (int i = 0; i < 65; i++) ch[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 65; i++) if (ch[i]) delete ch[i];
	}
	void insert(const char* s, bool b) {
		no = b;
		if (!*s) {
			if (!b)end = true;
			return;
		}
		int now;
		if (*s == '.') now = 26; //26
		else if (*s >= 'A' && *s <= 'Z') now = *s - 'A'; //0 ~ 25
		else if (*s >= '0' && *s <= '9') now = *s - '0' + 27; //27 ~ 36
		else now = *s - 'a' + 37; //37~62
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(s + 1, b);
	}
	int sol() {
		if (!no) return 1;
		int res = 0;
		if (end) res++;
		for (int i = 0; i < 65; i++) {
			if (ch[i]) res += ch[i]->sol();
		}
		return res;
	}
};

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		Trie* root = new Trie;
		int n1, n2; cin >> n1;
		string s;
		vector<string>v1, v2;
		for (int i = 0; i < n1; i++) {
			cin >> s;
			v1.push_back(s);
			root->insert(s.c_str(), false);
		}
		cin >> n2;
		for (int i = 0; i < n2; i++) {
			cin >> s;
			v2.push_back(s);
			root->insert(s.c_str(), true);
		}
		cout << root->sol() << '\n';

		delete root;
	}
}