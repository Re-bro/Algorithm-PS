/* [BOJ 14235] 크리스마스 선물
	Algorithm : Priority_queue

	현재 가지고 있는 선물이 없는 경우에는 -1을 출력하고, 있는 경우에 가장 큰 선물을 출력해야 하므로
	우선순위 큐를 이용한다.
*/

#include<bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (a > 0) {
			while (a--) {
				int k; cin >> k;
				pq.push(k);
			}
		}
		else {
			if (pq.empty()) cout << -1 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
}