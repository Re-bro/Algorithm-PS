/* [BOJ 3080] �Ƹ��ٿ� �̸�
	Algorithm : Trie

	�ܼ��� Ʈ���̸� ����� �޸� �ʰ��� ����. 
	���� �ʿ��� ��� ���� �ٿ���� �Ѵ�. 
	�־����� ���ڿ����� �����ϸ�, A[i]�� A[i-1] �Ǵ� A[i+1]�� ���� ���� prefix�� ��ģ��.
	��ġ�� �ʴ� ���� ������ ���ڵ��� �л����� ������ �ƹ� ������ ��ġ�� �ʴ´�. 
	(���̿� ���� ���ڿ��� �����Ƿ�)
	���� ��ġ�� �ʴ� ù��° �������� ���ڿ��� Ʈ���̿� �־��ָ� �ȴ�. 
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