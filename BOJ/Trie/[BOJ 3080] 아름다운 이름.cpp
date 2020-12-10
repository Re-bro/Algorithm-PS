/* [BOJ 3080] 아름다운 이름
	Algorithm : Trie

	단순히 트라이를 만들면 메모리 초과가 난다. 
	따라서 필요한 노드 수를 줄여줘야 한다. 
	주어지는 문자열들을 정렬하면, A[i]는 A[i-1] 또는 A[i+1]과 제일 많이 prefix가 겹친다.
	겹치지 않는 지점 이후의 문자들은 학생들의 순서에 아무 영향을 미치지 않는다. 
	(사이에 들어가는 문자열이 없으므로)
	따라서 겹치지 않는 첫번째 지점까지 문자열을 트라이에 넣어주면 된다. 
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int N; 
ll fac[100];
struct Trie {
	map<char, Trie *>ch;
	bool end;
	Trie() {
		end = false;
	}
	void insert(const char *s, int cnt) {
		if (cnt == -1 || !*s) {
			end = true;
			return;
		}
		int now = *s - 'A';
		if (ch.find(now) == ch.end()) ch[now] = new Trie;
		ch[now]->insert(s + 1, cnt-1);
	}
};
Trie *root;
ll sol(Trie * now) {
	int cnt = 0;
	ll res = 1;
	for (int i = 0; i < 26; i++) {
		if (now->ch.find(i) != now->ch.end()) {
			res *= sol(now->ch[i]);
			res %= MOD;
			cnt++;
		}
	}
	return (res * fac[cnt + (now->end ? 1 : 0)]) % MOD;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	fac[0] = 1;
	for (int i = 1; i <100; i++) {
		fac[i] = (fac[i - 1] * i)%MOD;
	}
	root = new Trie;
	vector<string> v;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		v.push_back(s);
	}
	sort(all(v));
	int pre = 0, post = 0;
	for (int i = 0; i < N; i++) {
		if (i == N - 1) {
			root->insert(v[i].c_str(), pre + 1);
		}
		else {
			for (int j = 0; j < sz(v[i]); j++) {
				if (v[i][j] != v[i + 1][j]) {
					break;
				}				
				post = j;
			}
			root->insert(v[i].c_str(), max(pre, post)+1);
			pre = post;
		}
	}
	cout << sol(root);
}