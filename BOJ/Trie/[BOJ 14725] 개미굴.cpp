/* [BOJ 14725] 개미굴
	Algorithm : Trie

	기존에 알파벳 한글자씩 노드를 만드는 트라이를, 
	노드에 하나의 단어가 들어가도록 map을 이용해서 만들어준다. 
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

struct Trie {
	map<string, Trie*> child;
	void insert(vector<string>&v, int idx) {
		if (idx == sz(v)) return;
		if (child.count(v[idx]) == 0) child[v[idx]] = new Trie;
		child[v[idx]]->insert(v, idx + 1);
	}
};
void dfs(Trie *T, int lv) {
	for (auto i : (*T).child) {
		for (int j = 1; j <= lv; j++) cout << "--";
		cout << i.first << '\n';
		dfs(i.second, lv + 1);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	Trie *root = new Trie;
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		int n; cin >> n;
		vector<string> v;
		while (n--) {
			string s; cin >> s;
			v.push_back(s);
		}
		root->insert(v, 0);
	}
	dfs(root, 0);
}