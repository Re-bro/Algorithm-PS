#include<bits/stdc++.h>
using namespace std;

struct Node {
	Node* ch[10];
	bool end; 
	bool ischild;

	Node() {
		end = false;
		ischild = false;
		for (int i = 0; i < 10; i++) ch[i] = NULL;
	}
	~Node() {
		for (int i = 0; i < 10; i++) if (ch[i]) delete ch[i];
	}
	void insert(const char* s) {
		if (!*s) {
			this->end = true;
			return;
		}
		int now = *s - '0';
		if (!ch[now]) ch[now] = new Node;
		ischild = true;
		ch[now]->insert(s + 1);
	}
	bool consis() {
		if (end && ischild) return false;
		for (int i = 0; i < 10; i++) {
			if (ch[i] && ch[i]->consis() == false) return false;
		}
		return true;
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		Node* root = new Node;
		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			root->insert(s.c_str());
		}
		if (root->consis()) cout << "YES\n";
		else cout << "NO\n";
		delete root;
	}
}