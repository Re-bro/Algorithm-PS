/* [BOJ 18323] Photoshoot
	Algorithm : Brute-force

	가능한 A[1]의 값을 모두 돌면서 완전탐색으로 만족하는 수열 A를 구한다.
	배열 index를 벗어나는 경우를 조심하자.
*/

#include<bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	vector<int> b(N);
	vector<int> a(N + 1);
	for (int i = 1; i < N; i++) cin >> b[i];
	for (int i = 1; i < b[1]; i++) {
		if (i > N) break;
		vector<bool> visited(N + 1, false);
		a[1] = i;
		visited[i] = true;
		bool chk = true;
		for (int j = 2; j <= N; j++) {
			int k = b[j - 1] - a[j - 1];
			if (k < 1 || k>N || visited[k]) {
				chk = false;
				break;
			}
			a[j] = k;
			visited[k] = true;
		}
		if (!chk) continue;
		else {
			for (int i = 1; i <= N; i++) cout << a[i] << ' ';
			return 0;
		}
	}
}