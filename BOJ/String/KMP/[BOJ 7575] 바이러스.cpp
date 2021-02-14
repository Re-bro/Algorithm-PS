/* [BOJ 7575] 바이러스
	Algorithm : KMP

	N개의 프로그램에서 연속된 K개 이상의 원소로 이루어진 공통된 부분 수열이 있는지를 찾는 것은,
	정확히 연속된 K개로 이루어진 공통 부분 수열이 있는지를 찾는 것으로 대체할 수 있다. 
	또, 한 프로그램에서 만들어질 수 있는 연속된 K개로 이루어진 부분 수열을 하나의 패턴으로 하여
	나머지 N-1개의 프로그램에 패턴이 일치하는 부분이 있는지를 체크한다. 
	반대로 일치해도 만족하므로, 문자열을 뒤집어서도 체크해준다. 

	시간복잡도는 O(K*N*(M+K)) 가 된다. 
	K : 패턴을 만드는 경우의 수
	N : 탐색하는 문자열의 수 (N-1개)
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