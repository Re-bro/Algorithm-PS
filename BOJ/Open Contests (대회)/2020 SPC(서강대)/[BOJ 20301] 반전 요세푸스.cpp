/* [BOJ 20301] 반전 요세푸스
	Algorithm : queue

	풀이 : https://wogud6792.tistory.com/78
*/


#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, K, M; cin >> N >> K >> M;
	queue<int> q;
	for (int i = 1; i <= N; i++) q.push(i);
	int cnt = 0;
	int cnt2 = 0;
	while (!q.empty()) {
		int a = q.front(); q.pop();
		cnt++;
		if (cnt == K) {
			cout << a << '\n';
			cnt = 0;
			cnt2++;
			if (cnt2 == M) {
				vector<int> v;
				while (!q.empty()) {
					v.push_back(q.front()); q.pop();
				}
				for (int i = sz(v) - 1; i >= 0; i--) q.push(v[i]);
				cnt2 = 0;
			}
		}
		else q.push(a);
	}
}