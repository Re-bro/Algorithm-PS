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
	//	freopen("input.txt", "r", stdin);
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