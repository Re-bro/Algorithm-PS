/* [BOJ 9249] ���� ���� �κ� ���ڿ�
	Algorithm : Suffix Array / LCP

	�� ���ڿ��� ���ļ� LCP�� �̿����� ������, LCP�� ���ϴ� ��������
	�ΰ��� �����Ͱ� ���� �ٸ� ���ڿ��� ����Ű�� �ִ��� üũ���־�� ��.
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
const int len = 1 << 20;
char S[len];
//pos : �׷��ȣ / sa[i] == [i, n-1] ���̻�
int N, d, sa[len], pos[len], tmp[len], lcp[len];
string s1, s2;
int idx, mx;
bool cmp(int i, int j) {
	//���� ��ġ�� ���ڸ� ��
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	//���ڰ� ������ dĭ ���� ���ڳ��� ��
	else return pos[i + d] < pos[j + d];
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

		if (mx < k && ((i < sz(s1) && sa[pos[i] + 1] > sz(s1)) || (i > sz(s1) && sa[pos[i] + 1] < sz(s1))) ){
			mx = k;
			idx = i;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> s1 >> s2;
	for (int i = 0; i < sz(s1); i++) S[i] = s1[i];
	S[sz(s1)] = '$';
	for (int i = 0; i < sz(s2); i++) S[i + sz(s1) + 1] = s2[i];
	S[sz(s1) + sz(s2) + 1] = 0;
	getSA();
	getLCP();
	
	for (int i = 0; i < N-1; i++) {
		if (mx < lcp[i] && lcp[i] <= min(sz(s1), sz(s2))) {
			mx = lcp[i];
			idx = i;
		}
	}
	//idx : ���� �� lcp�� �ִ� sa�� ��ġ
	cout << mx << '\n';
	for (int i = idx; i < idx + mx; i++) cout << S[i];
}