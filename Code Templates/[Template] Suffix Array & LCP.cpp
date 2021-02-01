#include<bits/stdc++.h>
using namespace std;

const int len = 1 << 20;
char S[len];
//pos : �׷��ȣ / sa[i] == [i, n-1] ���̻�
int N, d, sa[len], pos[len], tmp[len], lcp[len]; 

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
	cin >> S;
	getSA();
	getLCP();
}