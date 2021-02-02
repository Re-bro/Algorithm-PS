/* [BOJ 12917] ���ڿ� �Լ� ���
	Algorithm : Suffix Array / LCP / Union-find

	� �κ� ���ڿ��� 2�� �̻� �����Ѵٸ�, �� �̻��� suffix�� prefix�� ��Ÿ����.
	����, suffix array�� ����� �̿��� ���ҷ� ��Ÿ����, lcp �迭�� �� ���� 
	�ش� �κ� ���ڿ��� ���̺��� ũ�ų� ���� ������ ���´�.
	�׷��Ƿ�, lcp�迭���� ������ ���� [l, r]�� �ּڰ��� k���, ���̰� k�� �κ� ���ڿ��� r-l + 2�� �����Ѵٴ� �ǹ��̴�. 
	�̸� �� �����غ���, lcp�迭�� ������׷�ó�� ��Ÿ���� 
	������׷����� ���� �� �ִ� �ִ� ������ ���簢�� ������ ����������. 
	�̸� Union-find�� �ذ��Ѵ�.
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
using pii = pair<int, int>;
const int len = 1 << 20;
char S[len];
//pos : �׷��ȣ / sa[i] == [i, n-1] ���̻�
int N, d, sa[len], pos[len], tmp[len], lcp[len];

int P[100001];
int mi[100001];
int ans;
bool chk[100010];
int find(int a) {
	return P[a] < 0 ? a : P[a] = find(P[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (P[a] > P[b]) swap(a, b);
		P[a] += P[b];
		P[b] = a;
		mi[a] = min(mi[a], mi[b]);
		ans = max(ans, (-P[a] + 1)*mi[a]);
	}
}

bool cmp(int i, int j) {
	//���� ��ġ�� ���ڸ� ��
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	//���ڰ� ������ dĭ ���� ���ڳ��� ��
	i += d;
	j += d;
	return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}
void getSA() {
	N = strlen(S);
	for (int i = 0; i < N; i++) {
		sa[i] = i;
		pos[i] = S[i]; //ó������ �� ���ڷ� ��
	}
	for (d = 1; ; d *= 2) {
		sort(sa, sa + N, cmp);
		tmp[0] = 0; //�� �׷� ��ȣ
		for (int i = 0; i < N - 1; i++) {
			//�տ������� ���鼭, �� ���̻簡 ���� �ٸ� �׷쿡 ���� ������ ��ȣ ����
			tmp[i + 1] = tmp[i] + cmp(sa[i], sa[i + 1]);
		}
		for (int i = 0; i < N; i++) {
			pos[sa[i]] = tmp[i];		//pos ����
		}
		//��� ���̻簡 �ٸ� �׷����� ���������� ����
		if (tmp[N - 1] == N - 1) break;
	}
}
//sa ���� ��, O(n)
void getLCP() {
	//pos[i] = S[i, N-1]�� sa�� �� ��°�� �ִ��� (pos[sa[i]] = i) 
	//���� �� ���̻�(S)���� ����
	// �� �������� k>0�̸� k--
	for (int i = 0, k = 0; i < N; i++, k = max(k - 1, 0)) {
		if (pos[i] == N - 1) continue;
		//�ٷ� �� ������ ���̻�� ���Ͽ� �տ������� �� ���� ���ڰ� ��ġ�ϴ���
		for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k]; k++);
		lcp[pos[i]] = k;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> S;
	getSA();
	getLCP();
	ini(P, -1);
	ans = N;
	priority_queue<pii> pq;
	for (int i = 0; i < N - 1; i++) {
		mi[i] = lcp[i];
		pq.push({ lcp[i], i });
	}
	while (!pq.empty()) {
		auto[k, i] = pq.top(); pq.pop();
		if (chk[i + 1]) merge(i, i + 1);
		if (i > 0 && chk[i - 1]) merge(i - 1, i);
		chk[i] = true;
	}
	cout << ans;
}