/* [BOJ 9250] 문자열 집합 판별
	Algorithm : Aho-corasick Algorithm

	아호코라식 알고리즘을 그대로 이용하면 된다. 
*/

#include<bits/stdc++.h>
using namespace std;
struct Trie {
	Trie* ch[26];
	Trie* fail;
	bool end;
	Trie() {
		fill(ch, ch + 26, nullptr);
		end = false;
	}
	void insert(const char* s) {
		if (!*s) {
			end = true;
			return;
		}
		int now = *s - 'a';
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(s + 1);
	}
	void init() {
		queue<Trie*>q;
		q.push(this);
		while (!q.empty()) {
			Trie* now = q.front(); q.pop();
			for (int i = 0; i < 26; i++) {
				Trie* next = now->ch[i];
				if (!next) continue;
				if (now == this) next->fail = this;
				else {
					Trie* t = now->fail;
					while (t != this && t->ch[i] == NULL) t = t->fail;
					if (t->ch[i]) t = t->ch[i];
					next->fail = t;
				}
				if (next->fail->end) next->end = true;
				q.push(next);
			}
		}
	}
	bool query(string &s) {
		Trie* cur = this;
		for (int i = 0; i < s.size(); i++) {		
			int now = s[i] - 'a';
			while (cur != this && !(cur->ch[now])) {
				cur = cur->fail;
			}
			if (cur->ch[now]) cur = cur->ch[now];
			if (cur->end) return true;
		}
		return false;
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	Trie* root = new Trie;
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		root->insert(s.c_str());
	}
	root->init();
	int Q; cin >> Q;
	while (Q--) {
		string s; cin >> s;
		if (root->query(s)) cout << "YES\n";
		else cout << "NO\n";
	}
}