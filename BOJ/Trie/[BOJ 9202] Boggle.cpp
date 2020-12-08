/* [BOJ 9202] Boggle
	Algorithm : Trie / Graph search / Brute-force

	사전에 있는 단어를 모두 트라이에 넣어두고, Boggle에서 만들어질 수 있는
	모든 문자열들을 다 트라이에서 찾아본다. 
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;

int len[300001];
bool chk[300001];
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
bool visited[4][4];
vector<string> bog(4);
struct Trie {
	Trie* ch[26];
	bool end;
	int idx;
	Trie() {
		for (int i = 0; i < 26; i++) ch[i] = NULL;
		end = false;
		idx = -1;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
	}
	void insert(const char *s, int n) {
		if (!*s) {
			end = true;
			idx = n;
			return;
		}
		int now = *s - 'A';
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(s + 1, n);
	}
	int find(const char *s) {
		if (!*s) {
			if (end) return idx;
			else return 0;
		}
		if (!ch[*s - 'A']) return -1;
		return ch[*s-'A']->find(s+1);
	}
};
Trie *root;
vector<string> v;
void sol(string s, int x, int y) {
	int k = root->find(s.c_str());
	if (k == -1) return;
	else if (k > 0) {
		chk[k] = true;
	}
	if (sz(s) == 8) return;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && !visited[nx][ny]) {
			string tmp = s + bog[nx][ny];
			visited[nx][ny] = true;
			sol(tmp, nx, ny);
			visited[nx][ny] = false;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	root = new Trie;
	int w; cin >> w;
	for (int i = 0; i < w; i++) {
		string s; cin >> s;
		v.push_back(s);
		root->insert(s.c_str(), i+1);
		len[i + 1] = sz(s);
	}
	int b; cin >> b;
	while (b--) {
		for (int i = 1; i <= w; i++) chk[i] = false;
		for (int i = 0; i < 4; i++) cin >> bog[i];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				string s;
				s += bog[i][j];
				ini(visited, false);
				visited[i][j] = true;
				sol(s, i, j);
			}
		}
		string mx = "";
		int cnt = 0;
		int ans = 0;
		for (int i = 1; i <= w; i++) {
			if (chk[i]) {
				if (len[i] >= 3 && len[i] <= 4) ans++;
				else if (len[i] == 5) ans += 2;
				else if (len[i] == 6) ans += 3;
				else if (len[i] == 7) ans += 5;
				else if (len[i] == 8) ans += 11;
				if (sz(mx) < len[i] || (sz(mx) == len[i] && v[i - 1] < mx)) {
					mx = v[i - 1];
				}
				cnt++;
			}
		}
		cout << ans << ' ' << mx << ' ' << cnt << '\n';
	}
	delete root;
}