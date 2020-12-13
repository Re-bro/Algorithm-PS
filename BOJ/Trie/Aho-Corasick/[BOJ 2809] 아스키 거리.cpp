/* [BOJ 2809] �ƽ�Ű �Ÿ�
	Algorithm : Aho-corasick

	Ʈ������ �� ������ ���� �ش��ϴ� ��忡 ���� ��ȣ�� ����صд�.
	�׸��� ���� ������ �ʱ�ȭ�Ҷ�, �ش� ��忡�� ������ Ÿ�� �� ���� ���̰� �� Ÿ���� �����صд�.
	�� ��, �ƽ�Ű �Ÿ��� �� index���� ���� ��ġ�ϴ� Ÿ���� �ִ� ���, �ش� Ÿ���� ������ ���Ϳ� �����Ѵ�.
	���Ϳ� ����� Ÿ�ϵ鿡 ���Ե��� ���� ������ ������ ���Ѵ�.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
using namespace std;
using pii = pair<int, int>;

int len[5000];
int cnt[300001];
vector<pii> v;
struct Trie {
	vector<pair<char, Trie*>> ch;
	int end;
	Trie* fail;
	Trie() {
		end = -1;
		ch.clear();
		fail = nullptr;
	}
	void insert(const char* s, int num) {
		if (!*s) {
			end = num;
			return;
		}
		int now = *s - 'a';
		for (auto& i : ch) {
			if (i.first == now) return i.second->insert(s + 1, num);
		}
		ch.push_back({ now, new Trie });
		ch.back().second->insert(s + 1, num);
	}
	void init() {
		queue<Trie*> q;
		q.push(this);
		while (!q.empty()) {
			Trie* now = q.front(); q.pop();
			for (auto& i : now->ch) {
				Trie* next = i.second;
				if (now == this) next->fail = this;
				else {
					Trie* t = now->fail;
					while (t != this) {
						bool chk = true;
						for (auto j : t->ch) {
							if (j.first == i.first) {
								chk = false;
								break;
							}
						}
						if (!chk) break;
						t = t->fail;
					}
					for (auto j : t->ch) {
						if (j.first == i.first) {
							t = j.second;
							break;
						}
					}
					next->fail = t;
				}
				if (next->fail->end>=0) {
					if (next->end == -1 || (len[next->fail->end] > len[next->end])) {
						next->end = next->fail->end;
					}
				}
				q.push(next);
			}
		}
	}
	void query(const string& s) {
		Trie* cur = this;
		for (int i = 0; i < sz(s); i++) {
			int now = s[i] - 'a';
			while (cur != this) {
				bool chk = true;
				for (auto j : cur->ch) {
					if (j.first == now) {
						chk = false; 
						break;
					}
				}
				if (!chk) break;
				cur = cur->fail;
			}
			for (auto j : cur->ch) {
				if (j.first == now) {
					cur = j.second;
					break;
				}
			}
			if (cur->end >= 0) {
				v.push_back({ i - len[cur->end] + 1, i });
			}
		}
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	Trie* root = new Trie;
	int N; cin >> N;
	string s; cin >> s;
	int M; cin >> M;
	vector<string> tile(M);
	for (int i = 0; i < M; i++) {
		cin >> tile[i];
		len[i] = sz(tile[i]);
		root->insert(tile[i].c_str(), i);
	}
	root->init();
	root->query(s);
	sort(all(v));
	int last = -1;
	int ans = 0;
	for (int i = 0; i < sz(v); i++) {
		if (last < v[i].first) {
			ans += v[i].first - last-1;
		}
		last = max(last, v[i].second);
	}
	ans += sz(s) - 1 - last;
	cout << ans;

}