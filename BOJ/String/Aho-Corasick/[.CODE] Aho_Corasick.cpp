#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
//Aho-corasick /  O(N + M + P) 
// N = string len , M = sum of patterns' len , P = counts of patterns in string 
struct Trie {
	Trie* ch[26];
	Trie* fail; //실패함수. 매칭이 실패했을 때 이동하는 노드
				  // 이 노드 문자열의 접미사이면서 트라이에 포함된 최대 문자열
	int end; //현재 위치에서 끝나는 문자열의 번호
	vector<int> output; //현재 위치에서 끝나는 문자열 목록
	Trie() {
		end = 0;
		fill(ch, ch + 26, nullptr);
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
		delete fail;
	}
	void insert(const char* s, int num) { //num : 문자열의 번호
		if (!*s) {
			end = num;
			return;
		}
		int now = *s - 'a';
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(s + 1, num);
	}
	void init() {
		queue<Trie*> q;
		q.push(this);
		while (!q.empty()) {
			Trie* now = q.front(); q.pop();
			for (int i = 0; i < 26; i++) {
				Trie* next = now->ch[i];
				if (!next) continue;
				if (now == this) next->fail = this;
				else {
					//부모의 실패연결을 따라감
					Trie* t = now->fail;
					while (t != this && t->ch[i] == NULL) t = t->fail;
					if (t->ch[i]) t = t->ch[i];
					next->fail = t;
				}
				if (next->fail->end) next->end = true;
				q.push(next);

				//현재 위치에서 끝나는 문자열 목록 실패연결에서 가져옴
				next->output = next->fail->output;
				if (next->end > 0) next->output.push_back(next->end);
			}
		}
	}
	//string에 pattern이 있는지만 체크하는 함수
	bool query(const string& s) {
		Trie* cur = this;
		for (int i = 0; i < s.size(); i++) {
			int now = s[i] - 'a';
			while (cur != this && !(cur->ch[now])) cur = cur->fail;
			if (cur->ch[now]) cur = cur->ch[now];
			if (cur->end > 0) return true;
		}
		return false;
	}
	//pair<string idx, pattern num> 모두 찾는 함수. need Large memory
	vector<pii> findall(const string& s) {
		vector<pii> ret;
		Trie* cur = this;
		for (int i = 0; i < s.size(); i++) {
			int now = s[i] - 'a';
			while (cur != this && !(cur->ch[now])) cur = cur->fail;
			if (cur->ch[now]) cur = cur->ch[now];
			for (int j = 0; j < cur->output.size(); j++) {
				ret.push_back({ i+1, cur->output[j]}); 
			}
		}
		return ret;
	}
};

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	
}