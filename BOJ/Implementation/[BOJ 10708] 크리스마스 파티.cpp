/* [BOJ 10708] 크리스마스 파티
	Algorithm : Implementation
*/
#include<bits/stdc++.h>
using namespace std;
int A[101];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	int M; cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i];
	}
	vector<int> ans(N + 1);
	for (int i = 1; i <= M; i++) {
		vector<int>b(N + 1);
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			cin >> b[j];
			if (b[j] == A[i]) ans[j]++;
			else cnt++;
		}
		ans[A[i]] += cnt;
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
}