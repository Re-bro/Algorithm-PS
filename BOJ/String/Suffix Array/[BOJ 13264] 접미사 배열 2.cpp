/* [BOJ 13264] ���̻� �迭 2
	Algorithm : Suffix Array

	Suffix Array �⺻ ����
*/

#include<bits/stdc++.h>
using namespace std;
const int len = 1 << 18;
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
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> S;
	getSA();
	for (int i = 0; i < N; i++) cout << sa[i] << '\n';
}