/* [BOJ 2809] 아스키 거리
	Algorithm : Aho-corasick

	트라이의 각 패턴의 끝에 해당하는 노드에 패턴 번호를 기록해둔다.
	그리고 실패 연결을 초기화할때, 해당 노드에서 끝나는 타일 중 가장 길이가 긴 타일을 저장해둔다.
	그 후, 아스키 거리의 각 index별로 끝에 일치하는 타일이 있는 경우, 해당 타일의 구간을 벡터에 저장한다.
	벡터에 저장된 타일들에 포함되지 않은 문자의 개수를 구한다.
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