/*
	[BOJ 15764] Milking 
	Algorithm : Implementation / Case work
*/
#include<bits/stdc++.h>
using namespace std;
int m[101], res[101], pos[101];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M, K; cin >> N >> M >> K;
	bool chk = false;
	for (int i = 1; i <= M; i++) {
		cin >> m[i];
		if (m[i] == 1) chk = true;
	}
	for (int i = 1; i <= K; i++) {
		int c, p; cin >> c >> p;
		res[p] = c;
		pos[c] = p;
		if (c == 1) return cout << p, 0;
	}
	for (int i = 1; i <= N; i++) {
		int n = N;
		int midx = M;
		bool chk = true;
		if (res[i] > 0) continue;
		res[i] = 1; pos[1] = i;
		while (1) {
			if (pos[m[midx]] == 0) {
				if (res[n] == 0) {
					n--; 
					midx--;
				}
				else n--;
			}
			else {
				if (n < pos[m[midx]]) {
					chk = false; break;
				}
				n = pos[m[midx--]] - 1;
			}
			if (midx == 0) break;
			else if (n == 0) {
				chk = false;
				break;
			}
		}
		if (chk) {
			return cout << i, 0;
		}
		res[i] = 0;
	}
}