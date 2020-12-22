/* [CF 1463D] Pairs
	Algorithm : Two pointer / Greedy

	x�� �ּڰ��� �ִ��� ���Ѵ�. 
	x�� �ּڰ��� ���� ������ ��, �ִ����� b�� ���Ұ� �ִ��� ���� ���ԵǾ�� �ϹǷ�
	�ڿ������� ���� b�� ������ �����鼭 ���� ū a�� ������ ���� �����ش�.
	x�� �ִ��� ���� ������ ��, �ּڰ����� b�� ���Ұ� �ִ��� ���� ���ԵǾ�� �ϹǷ�
	�տ������� ���� b�� ������ ũ�鼭 ���� ���� a�� ������ ���� �������.
*/
#include<bits/stdc++.h>
using namespace std;

int b[200001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<bool>chk(2 * n + 1, false);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			chk[b[i]] = true;
		}
		vector<int> a;
		for (int i = 1; i <= 2 * n; i++) {
			if (chk[i] == false) a.push_back(i);
		}
		int idx = 0;
		int mx = 0;
		int mi = n;
		for (int i = 0; i < n; i++) {
			while (idx<n && b[i] > a[idx]) idx++;
			if (idx == n) break;
			mx++;
			idx++;
		}
		idx = n - 1;
		for (int i = n - 1; i >= 0; i--) {
			while (idx >= 0 && b[i] < a[idx]) idx--;
			if (idx == -1) break;
			mi--;
			idx--;
		}
		cout << mx - mi + 1 << '\n';
	}
}