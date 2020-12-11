/* [BOJ 18787] Mad Scientist
	Algorithm : Greedy 

	��ġ�ϴ� ������ �ٲٰ� �Ǹ� �ᱹ �ٽ� �ѹ� �� �ٲ���� �ϹǷ�
	�ش� ���� �¿츦 ���� �ѹ��� �ٲ��ִ� �Ͱ� �����ϴ�. 
	���� 	��ġ���� �ʴ� ���ڿ��� ������ ������ ���ϸ� �ȴ�.
*/

#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	string a, b; cin >> a >> b;
	int cnt = 0;
	bool chk = true;
	for (int i = 0; i < N; i++) {
		if (a[i] != b[i] && chk) {
			chk = false;
			cnt++;
		}
		else if (a[i] == b[i]) {
			chk = true;
		}
	}
	cout << cnt;
}