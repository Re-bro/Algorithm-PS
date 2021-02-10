/* [BOJ 10256] 돌연변이
	Algorithm : Aho-corasick
	
	돌연변이로 가능한 경우는 m^2이므로 직접 모든 돌연변이를 만들어 트라이에 넣는다.
	그리고, 모든 패턴의 길이가 같기 때문에, 단순히 해당 index에서 끝나는 패턴이 있는지만 체크하고
	있다면 ans++을 해주면 된다. 
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
int ans;
int tonum(char c) {
	if (c == 'A') return 0;
	else if (c == 'G') return 1;
	else if (c == 'T') return 2;
	else return 3;
}
struct Trie {
	Trie* ch[4];
	bool end;
	Trie* fail;
	Trie() {
		fill(ch, ch + 4, nullptr);
		end = 0;
		fail = nullptr;
	}
	~Trie() {
		for (int i = 0; i < 4; i++) if (ch[i]) delete ch[i];
	}
	void insert(const char* s) {
		if (!*s) {
			end = true;
			return;
		}
		int now = tonum(*s);
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(s + 1);
	}
	void init() {
		queue<Trie*>q;
		q.push(this);
		while (!q.empty()) {
			Trie* now = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				Trie* next = now->ch[i];
				if (!next) continue;
				if (now == this) next->fail = this;
				else {
					Trie* t = now->fail;
					while (t != this && !t->ch[i]) t = t->fail;
					if (t->ch[i]) t = t->ch[i];
					next->fail = t;
				}
				if (next->fail->end) next->end = true;
				q.push(next);
			}
		}
	}
	void query(const string& s) {
		Trie* cur = this;
		for (int i = 0; i < sz(s); i++) {
			int now = tonum(s[i]);
			while (cur != this && !(cur->ch[now])) cur = cur->fail;
			if (cur->ch[now]) cur = cur->ch[now];
			if (cur->end) ans++;
		}
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		string a, b; cin >> a >> b;
		Trie* root = new Trie;
		ans = 0;
		root->insert(b.c_str());
		for (int i = 0; i < sz(b); i++) {
			for (int j = i + 1; j < sz(b); j++) {
				string tmp = b;
				reverse(tmp.begin() + i, tmp.begin() + j + 1);
				root->insert(tmp.c_str());
			}
		}
		root->init();
		root->query(a);
		cout << ans << '\n'; 
		delete root;
	}
}