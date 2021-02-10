#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
//Aho-corasick /  O(N + M + P) 
// N = string len , M = sum of patterns' len , P = counts of patterns in string 
struct Trie {
	Trie* ch[26];
	Trie* fail; //�����Լ�. ��Ī�� �������� �� �̵��ϴ� ���
				  // �� ��� ���ڿ��� ���̻��̸鼭 Ʈ���̿� ���Ե� �ִ� ���ڿ�
	int end; //���� ��ġ���� ������ ���ڿ��� ��ȣ
	vector<int> output; //���� ��ġ���� ������ ���ڿ� ���
	Trie() {
		end = 0;
		fill(ch, ch + 26, nullptr);
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
		delete fail;
	}
	void insert(const char* s, int num) { //num : ���ڿ��� ��ȣ
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
					//�θ��� ���п����� ����
					Trie* t = now->fail;
					while (t != this && t->ch[i] == NULL) t = t->fail;
					if (t->ch[i]) t = t->ch[i];
					next->fail = t;
				}
				if (next->fail->end) next->end = true;
				q.push(next);

				//���� ��ġ���� ������ ���ڿ� ��� ���п��ῡ�� ������
				next->output = next->fail->output;
				if (next->end > 0) next->output.push_back(next->end);
			}
		}
	}
	//string�� pattern�� �ִ����� üũ�ϴ� �Լ�
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
	//pair<string idx, pattern num> ��� ã�� �Լ�. need Large memory
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