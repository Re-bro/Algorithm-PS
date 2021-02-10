/* [BOJ 19585] 전설
	Algorithm : Trie

	한 트라이에는 색상을 넣고 다른 트라이에는 닉네임을 뒤집어서 넣는다.
	쿼리가 들어올 때마다 prefix중 색상과 일치하는 index, 
	뒤집은 것의 prefix중 닉네임과 일치하는 index를 각각 저장하여 
	둘을 합쳤을 때 전체 문자열을 만족하면 True이다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
int chk[2001];
struct Trie {
	map<char, Trie*> ch;
	bool end;
	Trie() {
		end = false;
		ch.clear();
	}
	void insert(const char* s) {
		if (!*s) { 
			end = true;
			return;
		}
		int now = *s - 'a';
		if (ch.find(now) == ch.end()) ch[now] = new Trie;
		ch[now]->insert(s + 1);
	}
	void find(const char* s, int k, bool color) {
		if (end) chk[k]++;
		if (!*s) return;
		int now = *s - 'a';
		if (ch.find(now) == ch.end()) return;
		ch[now]->find(s + 1, color ? k + 1 : k-1 , color);
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int C, N; cin >> C >> N;
	Trie* root = new Trie;
	Trie* root2 = new Trie;
	for (int i = 1; i <= C; i++) {
		string s; cin >> s;
		root->insert(s.c_str());
	}
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		reverse(all(s));
		root2->insert(s.c_str());
	}
	int Q; cin >> Q;
	while (Q--) {
		string s; cin >> s;
		ini(chk, 0);
		root->find(s.c_str(), 0, true);
		reverse(all(s));
		root2->find(s.c_str(), sz(s), false);
		bool ans = false;
		for (int i = 0; i < sz(s); i++) if (chk[i] == 2) { ans = true; break; }
		if (ans) cout << "Yes\n";
		else cout << "No\n";
	}
}