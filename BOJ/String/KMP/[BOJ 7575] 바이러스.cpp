/* [BOJ 7575] ���̷���
	Algorithm : KMP

	N���� ���α׷����� ���ӵ� K�� �̻��� ���ҷ� �̷���� ����� �κ� ������ �ִ����� ã�� ����,
	��Ȯ�� ���ӵ� K���� �̷���� ���� �κ� ������ �ִ����� ã�� ������ ��ü�� �� �ִ�. 
	��, �� ���α׷����� ������� �� �ִ� ���ӵ� K���� �̷���� �κ� ������ �ϳ��� �������� �Ͽ�
	������ N-1���� ���α׷��� ������ ��ġ�ϴ� �κ��� �ִ����� üũ�Ѵ�. 
	�ݴ�� ��ġ�ص� �����ϹǷ�, ���ڿ��� ������� üũ���ش�. 

	�ð����⵵�� O(K*N*(M+K)) �� �ȴ�. 
	K : ������ ����� ����� ��
	N : Ž���ϴ� ���ڿ��� �� (N-1��)
	M+K : kmp
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
vector<int> fail;
vector<vector<int>> v;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	v.assign(n, vector<int>());
	for (int i = 0; i < n; i++) {
		int m; cin >> m;
		if (m < k) return cout << "NO", 0;
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			v[i].push_back(a);
		}
	}
	for (int i = 0; i < sz(v[0]) - k + 1; i++) {
		bool chk = true;
		fail.assign(k, 0);
		for (int j = 1, q = 0; j < k; j++) {
			while (q > 0 && v[0][i+j] != v[0][i+q]) q = fail[q - 1];
			if (v[0][i+j] == v[0][i+q]) fail[j] = ++q;
		}
		for (int j = 1; j < n; j++) {
			bool chk2 = false;
			for (int q = 0, w = 0; q < sz(v[j]); q++) {
				while (w > 0 && v[j][q] != v[0][i+w]) w = fail[w - 1];
				if (v[j][q] == v[0][i+w]) {
					if (w == k - 1) {
						chk2 = true;
						break;
					}
					else w++;
				}
			}
			if (!chk2) {
				for (int q = sz(v[j]) - 1, w = 0; q >= 0; q--) {
					while (w > 0 && v[j][q] != v[0][i + w]) w = fail[w - 1];
					if (v[j][q] == v[0][i + w]) {
						if (w == k - 1) {
							chk2 = true;
							break;
						}
						else w++;
					}
				}
			}
			if (!chk2) {
				chk = false; 
				break;
			}
		}
		if (chk) return cout << "YES", 0;
	}
	cout << "NO";
}