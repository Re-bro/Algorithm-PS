/* [BOJ 18878] Cereal
	Algorithm : Offline Query / Recursion

	�ҵ��� �ϳ��� �������� ����� �ƴ϶�, �Ųٷ� �Ҹ� �տ� ä������ ������� �ϸ� �� ���ϴ�.
	�Ҹ� �������� ������� �Ѵٸ� ���� second-favorite �ø����� ������ �Ұ� 
	first-favorite�� �������� �� �� �ֱ� ������ �̸� ��� üũ����� �Ѵ�.
	�ݸ� ä������ ������� �Ѵٸ�, �߰��Ǵ� �Ҵ� ������ first-favorite�� �������� �ǰ�, ������ �ҵ��� 
	��ĭ�� �з����� ������ �����ϸ� �ȴ�.
*/

#include<bits/stdc++.h>

using namespace std;

int now[100001];
int chk[100001];
int ans[100001];
int v[100001][3];
int N, M;
bool sol(int idx, int val) {
	if (idx == 0) return true;
	if (v[idx][1] == val && (chk[v[idx][2]] >= idx || chk[v[idx][2]] == 0)) {
		now[idx] = v[idx][2]; //�ι�° ���ҷ� �Ѱ���
		int k = chk[v[idx][2]]; //�ι�° ���Ҹ� ����ϴ� index = k
		chk[v[idx][2]] = idx; 
		return sol(k, now[idx]);
	}
	else {	
		now[idx] = 0;
		return false;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> v[i][1] >> v[i][2];
	}
	int cnt = 0;
	for (int i = N; i >= 1; i--) {
		now[i] = v[i][1]; // ù��° ���ҷ� ���
		if (chk[v[i][1]] == 0) { //ù��° ���Ұ� ���� �Ⱦ��� ���
			chk[v[i][1]] = i;	//v[i][1]�� i��° �������� ����
			cnt++;
		}
		else {
			int k = chk[v[i][1]]; //ù��° ���Ұ� ���Ǵ� index = k
			chk[v[i][1]] = i; //���� index�� �ٲ���
			if (sol(k, now[i])) cnt++; //now[i]�� ���� ����ϴ� index = k Ž��
		}
		ans[i] = cnt;
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
}